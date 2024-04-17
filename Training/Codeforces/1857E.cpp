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

int t;
ll n,prefix[SZ], suffix[SZ], res[SZ];
pll a[SZ];

bool cmpVal(pll x, pll y)
{
    return x.fi < y.fi;
}

bool cmpId(pll x, pll y)
{
    return x.se < y.se;
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i].fi;
            a[i].se = i;
        }
        sort(a+1,a+n+1,cmpVal);
        prefix[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + (i - 1)*(a[i].first - a[i-1].first);
        }
        suffix[n+1] = 0;
        for (int i = n; i >= 1; --i) {
            suffix[i] = suffix[i + 1] + (n - i)*(a[i+1].first - a[i].first);
        }
        for(int i = 1; i <= n; i++)
        {
            res[a[i].se] = prefix[i] + suffix[i];
        }
        for(int i = 1; i <= n; i++)
        {
            cout << res[i] + n << " ";
        }
        cout << '\n';
    }
}
