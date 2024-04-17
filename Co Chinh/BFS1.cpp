#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "BFS1"

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

int n,m,u,v, d[SZ];
vector<int> adj[SZ];
bool vis[SZ];
queue<int> qu;

void bfs()
{
    qu.push(1);
    d[1] = 0;
    vis[1] = true;
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for(int v : adj[u])
        {
            if(!vis[v])
            {
                vis[v] = true;
                qu.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(d,-1, sizeof(d));
    memset(vis, false, sizeof(vis));
    bfs();
    for(int i = 1; i <= n; i++)
    {
        cout << d[i] << '\n';
    }
}
