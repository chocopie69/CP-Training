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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,q;

struct Edge
{
    int v, w;
    Edge(int _v = 0, int _w = 0) : v(_v), w(_w) {}
};

vector<Edge> adj[SZ];

int h[SZ], d[SZ], up[SZ][20];

void dfs(int u, int prev)
{
    for(Edge e : adj[u])
    {
        int v = e.v, w = e.w;
        if(v == prev) continue;
        up[v][0] = u;
        for(int k = 1; k < 20; k++)
        {
            up[v][k] = up[ up[v][k-1] ][k-1];
        }
        h[v] = h[u] + 1;
        d[v] = d[u] + w;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if(h[u] != h[v])
    {
        if(h[u] < h[v]) swap(u,v);
        int diff = h[u] - h[v];
        for(int k = 0; k < 20; k++)
        {
            if(diff >> k & 1) u = up[u][k];
        }
    }
    if(u == v) return u;
    int lg = __lg(h[u]);
    for(int k = lg; k >= 0; k--)
    {
        if(up[u][k] != up[v][k])
        {
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1,0);
    while(q--)
    {
        int u,v;
        cin >> u >> v;
        int p = lca(u,v);
        cout << d[u] + d[v] - 2*d[p] << '\n';
    }
}
