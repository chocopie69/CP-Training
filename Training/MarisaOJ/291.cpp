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

int n,m,u,v, dp[SZ][26];
string s;
vector<int> topo, adj[SZ];
bool vis[SZ];

void dfs(int u)
{
    vis[u] = true;
    for(int v : adj[u])
    {
        if(vis[v]) continue;
        dfs(v);
    }
    topo.push_back(u);
}

int id(int u)
{
    return int(s[u]) - 'a';
}

int main()
{
    init();
    cin >> n >> m >> s;
    s = " " + s;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i]) dfs(i);
    }
    u = topo[0];
    dp[u][id(u)] = 1;
    for(int i = 1; i < topo.size(); i++)
    {
        int u = topo[i];
        for(int i = 0; i <= 25; i++)
        {
            dp[u][i] = (id(u) == i);
        }
        for(int v : adj[u])
        {
            for(int i = 0; i <= 25; i++)
            {
                dp[u][i] = max(dp[u][i], dp[v][i] + (id(u) == i));
            }
        }
    }
    int res = 1;
    for(int u = 1; u <= n; u++)
    {
        for(int i = 0; i <= 25; i++)
        {
            res = max(res,dp[u][i]);
        }
    }
    cout << res;
}
