#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,a[SZ],m,x,y,sum[SZ], mn = INFLL;

bool check(ll val)
{
    int pos = 1;
    if(mn < x)
    {
        pos = lower_bound(a+1,a+n+1,x-val) - a;
    }
    if(pos == n+1) return false;
    if(a[pos] < x)
        val -= x - a[pos];
    return sum[pos-1] + (sum[n] - sum[pos]) + val >= y;
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mn = min(mn,a[i]);
    }
    sum[0] = 0;
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i];
    }
    cin >> m;
    while(m--)
    {
        cin >> x >> y;
        ll lo = 0, hi = x+y, mid;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(check(mid))
            {
                hi = mid-1;
            } else
            {
                lo = mid+1;
            }
        }
        cout << lo << '\n';
    }
//    x = 7, y = 9;
//    cout << check(2);
}

