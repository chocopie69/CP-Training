#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "FILL"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18, P = 1e4;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Rect
{
    ll b, h, w, d;
};

ll n, v, t;
Rect a[SZ];

int main()
{
    init();
    cin >> n >> v;
    v *= P;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].b >> a[i].h >> a[i].w >> a[i].d;
//        a[i].b *= P;
//        a[i].h *= P;
//        a[i].w *= P;
//        a[i].d *= P;
    }
    cin >> t;
    ll lo = 1*P, hi = 40002*P;
    cout << v << '\n';
    while(lo <= hi)
    {
        ll mid = (lo + hi)/2, curV = 0;
        mid /= P;
        for(int i = 1; i <= n; i++)
        {
            curV += min(a[i].h, max(mid-a[i].b,0LL))*a[i].w*a[i].d;
        }
        curV *= P;
        if(curV <= v)
        {
            lo = mid*P + 1;
            cout << curV << ' ' << mid << " 1" << '\n';
        } else
        {
            hi = mid*P - 1;
           cout << curV << ' ' << mid << " 2" << '\n';
        }
    }
    cout << fixed << setprecision(2) << hi / P;
}

