#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 5e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,k, s[SZ], h[SZ], up[SZ][20], sum[SZ];
vector<int> adj[SZ], adj2[SZ], vec[SZ];
vector<pii> edges;

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
        return (par[u] == u ? u : par[u] = get(par[u]));
    }

    void join(int u, int v)
    {
        u = get(u);
        v = get(v);
        if(u == v) return;
        if(s[u] < s[v]) swap(u,v);
        par[v] = u;
        s[u] += s[v];
    }

    bool joined(int u, int v)
    {
        u = get(u);
        v = get(v);
        return u == v;
    }
} dsu;

void dfs1(int u, int pre)
{
    for(int v : adj[u])
    {
        if(v == pre) continue;
        up[v][0] = u;
        for(int i = 1; i < 20; i++)
        {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        h[v] = h[u] + 1;
        dfs1(v, u);
    }
}

int lca(int u, int v)
{
    if(h[u] != h[v])
    {
        if(h[u] < h[v]) swap(u,v);
        int dif = h[u] - h[v];
        for(int i = 0; i < 20; i++)
        {
            if(dif >> i & 1) u = up[u][i];
        }
    }
    if(u == v) return u;
    for(int i = 19; i >= 0; i--)
    {
        if(up[u][i] == up[v][i]) continue;
        u = up[u][i];
        v = up[v][i];
    }
    return up[u][0];
}

void dfs2(int u, int pre)
{
    for(int v : adj[u])
    {
        if(v == pre) continue;
        dfs2(v, u);
        sum[u] += sum[v];
    }
    if(sum[u] > 0) dsu.join(s[u],s[pre]);
}
int leaf = 0;

void dfs3(int u, int pre)
{
    if(adj2[u].size() == 1) leaf++;
    for(int v : adj2[u])
    {
        if(v == pre) continue;
        dfs3(v, u);
    }
}

int main()
{
    init();
    cin >> n >> k;
    dsu.init(n);
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edges.pb({u,v});
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        vec[s[i]].pb(i);
    }
    dfs1(1, 0);
    for(int i = 1; i <= k; i++)
    {
        int root = vec[i][0];
        for(int j = 1; j < vec[i].size(); j++)
        {
            root = lca(root, vec[i][j]);
        }
        for(int j : vec[i])
        {
            sum[j]++;
        }
        sum[root] -= vec[i].size();
    }
    dfs2(1, 0);
    for(pii e : edges)
    {
        int u = dsu.get(s[e.fi]), v = dsu.get(s[e.se]);
        if(u == v) continue;
        adj2[u].pb(v);
        adj2[v].pb(u);
    }
    for(int i = 1; i <= k; i++)
    {
        if(adj2[i].size())
        {
            dfs3(i,0);
            break;
        }
    }
    cout << (leaf + 1) / 2;
}

