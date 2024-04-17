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

const int SZ = 7e4+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,q, seg[4*SZ], up[SZ][20], h[SZ];
vector<int> adj[SZ];

void dfs(int u)
{
    for(int v : adj[u])
    {
        if(v == up[u][0]) continue;
        up[v][0] = u;
        for(int i = 1; i < 20; i++)
        {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        h[v] = h[u] + 1;
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
    if(u == -1) return v;
    if(v == -1) return u;
    if(h[u] < h[v]) swap(u,v);
    int k;
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

void build(int id, int lo, int hi)
{
    if(lo == hi)
    {
        seg[id] = lo;
        return;
    }
    int mid = (lo + hi) / 2;
    build(2*id,lo,mid);
    build(2*id+1,mid+1,hi);
    seg[id] = lca(seg[2*id],seg[2*id+1]);
}

int query(int id, int lo, int hi, int u, int v)
{
    if(lo > v || hi < u) return -1;
    if(lo >= u && hi <= v) return seg[id];
    int mid = (lo + hi) / 2;
    return lca(query(2*id,lo,mid,u,v),query(2*id+1,mid+1,hi,u,v));
}

ll st[30][SZ];

void rmq()
{
    for (ll i = 1; i <= n; ++i) st[0][i] = i;
    for (ll j = 1; (1 << j) <= n; ++j)
        for (ll i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = lca(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}

ll getQuery(ll l, ll r)
{
    ll k = __lg(r - l + 1);
    return lca(st[k][l], st[k][r - (1 << k) + 1]);
}

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    build(1,1,n);
    rmq();
    while(q--)
    {
        int u,v;
        cin >> u >> v;
        //cout << query(1,1,n,u,v) << '\n';
        cout << getQuery(u,v) << '\n';
    }
}
