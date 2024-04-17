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

struct Edge
{
    int v;
    ll w;
    Edge(int _v = 0, ll _w = 0)
    {
        v = _v;
        w = _w;
    }
};

vector<Edge> adj[SZ];

vector<int> rtopo;

int vis[SZ];

void dfs(int u)
{
    vis[u] = 1;
    for(Edge e : adj[u])
    {
        int v = e.v;
        if(!vis[v]) dfs(v);
    }
    rtopo.push_back(u);
    vis[u] = 2;
}

int n,m;
ll dp[SZ], res = 0;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    rtopo.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i]) dfs(i);
    }
    for(int i = 1; i <= n; i++)
    {
        int u = rtopo[i];
        for(Edge e : adj[u])
        {
            int v = e.v;
            ll w = e.w;
            dp[u] = max(dp[u],dp[v] + w);
        }
        res = max(res, dp[u]);
    }
    cout << res;
}
