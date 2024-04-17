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

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,k,a[SZ], dp[SZ][40], res = 0;
vector<int> adj[SZ];

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int u = 1; u <= n; u++)
    {
        dp[u][1 << a[u]] = 1;
    }
    for(int mask = 1; mask < (1 << k); mask++)
    {
        for(int u = 1; u <= n; u++)
        {
            if(mask >> a[u] & 1)
            {
                for(int v : adj[u])
                {
                    dp[u][mask] += dp[v][mask - (1 << a[u])];
                }
                res += dp[u][mask];
//                cout << dp[u][mask] << " " << u << " ";
//                for(int i = k-1; i >= 0; i--)
//                {
//                    cout << (mask >> i & 1);
//                }
//                cout << '\n';
            }
        }
    }
    cout << res - n;
}
