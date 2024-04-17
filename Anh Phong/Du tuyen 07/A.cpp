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

const int SZ = 5e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

struct Edge
{
    int v;
    ll w;
    Edge(int _v = 0, ll _w = 0) : v(_v), w(_w) {}
};

int n,k, num[SZ], timer = 0, nodes[SZ], up[SZ][20], h[SZ];
vector<Edge> adj[SZ];
bool a[SZ];
ll d[SZ], dp[SZ], mx[SZ];

void dfs(int u, int prev)
{
    num[u] = ++timer;
    if(a[u]) dp[u] = 0;
    for(Edge e : adj[u])
    {
        int v = e.v;
        ll w = e.w;
        if(v == prev) continue;
        h[v] = h[u] + 1;
        d[v] = d[u] + w;
        up[v][0] = u;
        for(int i = 1; i < 20; i++)
        {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        dfs(v, u);
        if(dp[v] >= 0) dp[u] = max(dp[u], dp[v] + w);
    }
}

int lca(int u, int v)
{
    bool flag = false;
    if(u == 2 && v == 5) flag = true;
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
    for(int k = 19; k >= 0; k--)
    {
        if(up[u][k] != up[v][k])
        {
            u = up[u][k];
            v = up[v][k];
        }
    }
    return up[u][0];
}

void dfs2(int u, int prev, ll cur)
{
    mx[u] = max(dp[u], cur);
    multiset<pair<ll,int>> ms;
    for(Edge e : adj[u])
    {
        int v = e.v;
        ll w = e.w;
        if(v == prev) continue;
        ms.insert({-(dp[v] + w), v});
    }
    for(Edge e : adj[u])
    {
        int v = e.v;
        ll w = e.w;
        if(v == prev) continue;
        ms.erase({-(dp[v] + w), v});
        dfs2(v, u, w + max(cur, -1LL*(*ms.begin()).fi ));
        ms.insert({-(dp[v] + w), v});
    }
}

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i < n; i++)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    for(int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        a[x] = true;
        nodes[i] = x;
    }
    for(int i = 0; i < SZ; i++)
    {
        dp[i] = -INFLL;
    }
    h[1] = 1;
    dfs(1, 1);
//    for(int i = 1; i <= n; i++)
//    {
//        cout << dp[i] << " ";
//    }
    sort(nodes + 1, nodes + k + 1,[&](const int &i, const int &j){
        return num[i] < num[j];
    });
    ll sum = 0;
    nodes[k+1] = nodes[1];
    int root = nodes[1];
    for(int i = 1; i <= k; i++)
    {
        int u = nodes[i], v = nodes[i+1];
        //cout << root << " " << v << " - " << lca(root, v) << '\n';
        root = lca(root, v);
        int p = lca(u, v);
        sum += d[u] + d[v] - 2*d[p];
        //cout << u << " " << v << " " << p << '\n';
    }
    dfs2(1, 1, -INFLL);
    for(int i = 1; i <= n; i++)
    {
        int u = i;
        for(int j = 19; j >= 0; j--)
        {
            if(up[u][j] != 0 && dp[up[u][j]] < 0) u = up[u][j];
        }
        if(dp[u] < 0) u = up[u][0];
        ll mn = d[i] - d[u];
        if(h[u] < h[root]) mn += d[root] - d[u];
        //cout << sum << " " << mn << " " << u << " " << mx[i] << ' ';
        cout << sum + mn*2 - mx[i] << '\n';
    }
    //cout << root << " " << sum;
}

