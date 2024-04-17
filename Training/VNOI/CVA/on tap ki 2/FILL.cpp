#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "FILL"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Rect
{
    long double b, h, w, d;
};

long double n, v, t;
Rect a[SZ];

int main()
{
    init();
    cin >> n >> v;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].b >> a[i].h >> a[i].w >> a[i].d;
    }
    cin >> t;
    long double lo = 0, hi = 40002;
    while(hi - lo >= epsilon)
    {
        long double mid = (lo + hi)/2, curV = 0;
        for(int i = 1; i <= n; i++)
        {
            curV += min(a[i].h, max(mid-a[i].b,(long double) 0))*a[i].w*a[i].d;
        }
        if(curV <= v)
        {
            lo = mid;
            //cout << curV << '\n';
        } else
        {
            hi = mid;
        }
    }
    cout << fixed << setprecision(2) << hi;
}

