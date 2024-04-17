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

const int SZ = 1e6+50;
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
    ll v, w;
    Edge(ll _v = 0, ll _w = 0)
    {
        v = _v;
        w = _w;
    }
};

struct FullEdge
{
    ll u, v, w, pos;
    FullEdge(ll _u = 0, ll _v = 0, ll _w = 0, ll _pos = 0)
    {
        u = _u;
        v = _v;
        w = _w;
        pos = _pos;
    }
};

struct Node
{
    ll u, dist;
    Node(ll _u = 0, ll _dist = 0)
    {
        u = _u;
        dist = _dist;
    }
};

struct DSU
{
    int par[SZ], s[SZ];
    void init(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            par[i] = i;
            s[i] = 1;
        }
    }

    int get(int u)
    {
        return u == par[u] ? u : par[u] = get(par[u]);
    }

    bool joined(int u, int v)
    {
        u = get(u);
        v = get(v);
        if(u == v) return true;
        if(s[u] < s[v]) swap(u,v);
        par[v] = u;
        s[u] += s[v];
        return false;
    }
} dsu;

ll n,m,q, h[SZ], dTree[SZ], d[SZ][25], up[SZ][25];
bool inTree[SZ], check[SZ];
vector<Edge> adj[SZ];
vector<FullEdge> edges;
vector<int> vertices;

void dfs(int u)
{
    for(Edge e : adj[u])
    {
        int v = e.v;
        ll w = e.w;
        if(v == up[u][0]) continue;
        up[v][0] = u;
        for(int i = 1; i <= 17; i++)
        {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        h[v] = h[u] + 1;
        dTree[v] = dTree[u] + w;
        dfs(v);
    }
}

int lca(int u, int v)
{
    int k;
    if(h[u] != h[v])
    {
        if(h[u] < h[v]) swap(u,v);
        k = h[u] - h[v];
        for(int i = 0; (1 << i) <= k; i++)
        {
            if(k >> i & 1) u = up[u][i];
        }
    }
    if(u == v) return u;
    k = __lg(h[u]);
    for(int i = k; i >= 0; i--)
    {
        if(up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

struct cmp
{
    bool operator () (Node x, Node y)
    {
        return x.dist > y.dist;
    }
};

priority_queue<Node, vector<Node>, cmp> pq;

void dijkstra(int s, int cur)
{
    for(int i = 1; i <= n; i++)
    {
        d[i][cur] = INFLL;
    }
    d[s][cur] = 0;
    pq.push({s,0});
    while(!pq.empty())
    {
        Node x = pq.top();
        pq.pop();
        int u = x.u;
        ll dist = x.dist;
        if(d[u][cur] < dist) continue;
        for(Edge e : adj[u])
        {
            int v = e.v;
            ll w = e.w;
            if(d[v][cur] > dist + w)
            {
                d[v][cur] = dist + w;
                pq.push({v,dist + w});
            }
        }
    }
}

ll getAns(int u, int v)
{
    ll res;
    int p = lca(u,v);
    res = dTree[u] + dTree[v] - 2 * dTree[p];
    for(int i = 0; i < vertices.size(); i++)
    {
        res = min(res,d[u][i] + d[v][i]);
    }
    return res;
}

int main()
{
    init();
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w,i});
    }
    dsu.init(n);
    memset(inTree,false,sizeof(inTree));
    memset(check,false,sizeof(check));
    for(FullEdge e : edges)
    {
        int u = e.u;
        int v = e.v;
        ll w = e.w;
        int pos = e.pos;
        if(dsu.joined(u,v)) continue;
        inTree[pos] = true;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dTree[1] = 0;
    h[1] = 0;
    dfs(1);
    for(FullEdge e : edges)
    {
        int u = e.u;
        int v = e.v;
        ll w = e.w;
        int pos = e.pos;
        if(inTree[pos]) continue;
        if(!check[u])
        {
            vertices.push_back(u);
            check[u] = true;
        }
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i = 0; i < vertices.size(); i++)
    {
        int cur = vertices[i];
        dijkstra(cur,i);
    }
    while(q--)
    {
        int u,v;
        cin >> u >> v;
        cout << getAns(u,v) << '\n';
    }
}
