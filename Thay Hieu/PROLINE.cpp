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

const int SZ = 1e4+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,a[SZ], dp[SZ][SZ], res = 0, f[1000005];

void add(ll &x, ll y)
{
    x += y;
    if(x >= MOD) x -= MOD;
}

namespace sub3
{
    void solve()
    {
        for(int i = 1; i < n; i++)
        {
            for(int j = i+1; j <= n; j++)
            {
                if(a[i] >= a[j]) continue;
                dp[i][j] = 1;
                for(int k = 1; k <= i-1; k++)
                {
                    if(a[j] - a[i] == a[i] - a[k]) add(dp[i][j],dp[k][i]);
                }
                add(res,dp[i][j] - 1);
            }
        }
        cout << res;
    }
}

namespace sub5
{
    void solve()
    {
        for(int i = 1; i < n; i++)
        {
            /// f[x] là tổng dp[k][i] với h[k] = x
            for(int k = 1; k < i; k++)
            {
                if(a[k] >= a[i]) continue;
                add(f[a[i]-a[k]],dp[k][i]);
            }
            for(int j = i+1; j <= n; j++)
            {
                if(a[i] >= a[j]) continue;
                dp[i][j] = 1;
                add(dp[i][j],f[a[j]-a[i]]);
                add(res,dp[i][j] - 1);
            }
            for(int k = 1; k < i; k++)
            {
                if(a[k] >= a[i]) continue;
                f[a[i]-a[k]] = 0;
            }
        }
        cout << res;
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
//    if(n <= 500)
//        sub3::solve();
//    else
        sub5::solve();
}
