#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "MSTONE"

using namespace std;

const int LIMIT = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Edge
{
    int v,id;
    Edge(int _v, int _id)
    {
        v = _v;
        id = _id;
    }
};

int n,m;
vector<Edge> adj[LIMIT];
bool visited[LIMIT], visitedEdge[LIMIT];

void dfs(int u)
{
    visited[u] = true;
    for(Edge e : adj[u])
    {
        int v = e.v, id = e.id;
        if(visitedEdge[id]) continue;
        cout << id << " ";
        visitedEdge[id] = true;
        if(!visited[v]) dfs(v);
        cout << id << " ";
    }
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    memset(visited,false,sizeof(visited));
    memset(visitedEdge,false,sizeof(visitedEdge));
    dfs(1);
}

