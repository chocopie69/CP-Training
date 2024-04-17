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

const int SZ = 1e4+5, MAXLOG = 17;
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
    int v, w;

    Edge(int _v = 0, int _w = 0)
    {
        v = _v;
        w = _w;
    }
};

int t,n,u,v,w,k,up[SZ][MAXLOG], h[SZ], d[SZ];
string s;
vector<Edge> adj[SZ];

void dfs(int u)
{
    for(Edge e : adj[u])
    {
        v = e.v;
        w = e.w;
        if(v == up[u][0]) continue;
        h[v] = h[u] + 1;
        d[v] = d[u] + w;
        up[v][0] = u;
        for(int i = 1; i < MAXLOG; i++)
        {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        dfs(v);
    }
}

int goUp(int u, int k)
{
    for(int i = 0; (1 << i) <= k; i++)
    {
        if(k >> i & 1)
        {
            u = up[u][i];
        }
    }
    return u;
}

int lca(int u, int v)
{
    if(h[u] < h[v]) swap(u,v);
    int k = h[u]-h[v];
    u = goUp(u,k);
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

int dist(int u, int v)
{
    return d[u] + d[v] - 2*d[lca(u,v)];
}

int getNode(int u, int v, int k)
{
    k--;
    int p = lca(u,v), x = h[u] - h[p];
    if(x >= k)
    {
        return goUp(u,k);
    } else
    {
        k = (h[v] - h[p]) - (k - x);
        return goUp(v,k);
    }
}

void reset()
{
    h[1] = 0;
    d[1] = 0;
    for(int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        reset();
        for(int i = 1; i < n; i++)
        {
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(1);
        while(cin >> s)
        {
            if (s == "DIST")
            {
                cin >> u >> v;
                cout << dist(u,v) << '\n';
            }
            else if(s == "KTH")
            {
                cin >> u >> v >> k;
                cout << getNode(u,v,k) << '\n';
            } else break;
        }
        cout << '\n';
    }
}
