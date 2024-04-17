#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "DFS"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,u,v, trace[SZ];
vector<int> adj[SZ];
bool vis[SZ];

void recur(int u)
{
    if(u == -1) return;
    recur(trace[u]);
    cout << u << " ";
}


void dfs(int u)
{
    vis[u] = true;
    if(u == n)
    {
        recur(u);
        return;
    }
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            trace[v] = u;
            dfs(v);
        }
    }
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    memset(vis,false,sizeof(vis));
    memset(trace,-1, sizeof(trace));
    dfs(1);
}

