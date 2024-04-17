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

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

struct Edge
{
    int v, id;
    Edge(int _v = 0, int _id = 0) : v(_v), id(_id) {}
};

int n, m, k, num[SZ], s[SZ], up[SZ][18], h[SZ], timer = 0, c[SZ], b[SZ], sum[SZ];
vector<Edge> adj[SZ];
vector<int> a[SZ];

void dfs(int u, int prev)
{
    num[u] = ++timer;
    for(Edge e : adj[u])
    {
        int v = e.v, id = e.id;
        if(v == prev) continue;
        up[v][0] = u;
        for(int i = 1; i < 18; i++)
        {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        c[v] = id;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    if(h[u] != h[v])
    {
        if(h[u] < h[v]) swap(u, v);
        int diff = h[u] - h[v];
        for(int i = 0; i < 18; i++)
        {
            if(diff >> i & 1) u = up[u][i];
        }
    }
    if(u == v) return u;
    for(int i = 17; i >= 0; i--)
    {
        if(up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void inc(int u, int v)
{
    int p = lca(u, v);
    b[u]++;
    b[v]++;
    b[p] -= 2;
}

bool cmp(int x, int y)
{
    return num[x] < num[y];
}

void dfs2(int u, int prev)
{
    sum[u] = b[u];
    for(Edge e : adj[u])
    {
        int v = e.v;
        if(v == prev) continue;
        dfs2(v, u);
        sum[u] += sum[v];
    }
}

vector<int> res;

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> s[i];
        for(int j = 1; j <= s[i]; j++)
        {
            int x;
            cin >> x;
            a[i].pb(x);
        }
    }
    dfs(1, 1);
    for(int i = 1; i <= m; i++)
    {
        sort(all(a[i]), cmp);
        a[i].pb(a[i][0]);
        for(int j = 0; j < a[i].size() - 1; j++)
        {
            int u = a[i][j], v = a[i][j+1];
            inc(u, v);
        }
    }
    dfs2(1, 1);
    for(int i = 2; i <= n; i++)
    {
        if(sum[i] >= k*2) res.pb(c[i]);
    }
    sort(all(res));
    cout << res.size() << '\n';
    for(int x : res) cout << x << " ";
}

