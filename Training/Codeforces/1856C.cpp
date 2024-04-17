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

ll t,n,k,a[SZ], mx;

bool check(ll x)
{
    if(x <= mx) return true;
    bool flag = false;
    for(int i = 1; i < n; i++)
    {
        ll sum = 0, pos = 0;
        for(int j = i; j <= n; j++)
        {
            if(a[j] >= x - pos)
            {
                if(sum <= k) return true;
                break;
            } else
            {
                sum += (x - pos) - a[j];
            }
            pos++;
        }
    }
    return false;
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        mx = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mx = max(mx,a[i]);
        }
        ll lo = 1, hi = 1e9, mid;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(check(mid))
            {
                lo = mid+1;
            } else
            {
                hi = mid-1;
            }
        }
        cout << hi << '\n';
    }
}
