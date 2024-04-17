#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "BFS"

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

int n,m,u,v, trace[SZ], d[SZ];
vector<int> adj[SZ];
bool vis[SZ];
queue<int> qu;

void bfs(int s, int t)
{
    memset(trace,-1,sizeof(trace));
    memset(vis,false,sizeof(vis));
    vis[s] = true;
    d[s] = 0;
    qu.push(s);
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for(int v : adj[u])
        {
            if(vis[v]) continue;
            vis[v] = true;
            trace[v] = u;
            d[v] = d[u] + 1;
            qu.push(v);
        }
    }
}

void tracePath(int t)
{
    if(t == -1) return;
    tracePath(trace[t]);
    cout << t << " ";
}

int main()
{
    init();
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bfs(1,n);
    tracePath(n);
}

