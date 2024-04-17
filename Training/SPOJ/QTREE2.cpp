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

const int SZ = 1e4+5;
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
    int v,w;
    Edge(int _v = 0, int _w = 0)
    {
        v = _v;
        w = _w;
    }
};

int t,n,u,v,w,a,b,k, h[SZ], d[SZ], up[SZ][20];
vector<Edge> adj[SZ];
string s;

void reset()
{
    h[1] = 0;
    d[1] = 0;
    for(int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }
    memset(up,0,sizeof(up));
}

void dfs(int u)
{
    for(Edge e : adj[u])
    {
        int v = e.v, w = e.w;
        if(v == up[u][0]) continue;
        up[v][0] = u;
        for(int i = 1; i < 20; i++)
        {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        h[v] = h[u] + 1;
        d[v] = d[u] + w;
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
    if(h[u] != h[v])
    {
        k = h[u] - h[v];
        u = goUp(u,k);
    }
    if(u == v) return v;
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
            if(s == "DONE") break;
            cin >> a >> b;
            int p = lca(a,b);
            if(s == "DIST")
            {
                cout << d[a] + d[b] - 2 * d[p] << '\n';
            } else
            {
                cin >> k;
                k--;
                if(h[a] - h[p] >= k)
                {
                    cout << goUp(a,k) << '\n';
                } else
                {
                    k = h[a] + h[b] - 2*h[p] - k;
                    cout << goUp(b,k) << '\n';
                }
            }
        }
        cout << '\n';
    }
}
