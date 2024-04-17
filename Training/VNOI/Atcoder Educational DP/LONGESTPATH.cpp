#include <bits/stdc++.h>
#define ll long long
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

int n,m,u,v, dp[SZ], res = 1;
vector<int> adj[SZ];

void dfs(int u)
{
    if(dp[u] != -1) return;
    if(adj[u].empty()) dp[u] = 0;
    for(int v : adj[u])
    {
        dfs(v);
        dp[u] = max(dp[u],dp[v] + 1);
    }
}

int main()
{
    init();
    cin >> n >> m;
    memset(dp,-1,sizeof(dp));
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
    {
        dfs(i);
    }
    for(int i = 1; i <= n; i++)
    {
        res = max(res,dp[i]);
    }
    cout << res;
}
