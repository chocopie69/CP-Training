#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

#define TASKNAME "NAME"

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

struct Edge
{
    int v;
    ll w;
    Edge(int _v = 0, ll _w = 0) : v(_v), w(_w) {}
};

int n,l, s[SZ];
ll x, res = 0;
bool deleted[SZ];
vector<pll> v1, v2;
vector<Edge> adj[SZ];

struct FenwickTree
{
    ll nodes[SZ];

    void update(int pos, int val)
    {
        while(pos <= n+1)
        {
            nodes[pos] += val;
            pos += pos & (-pos);
        }
    }

    ll query(int pos)
    {
        ll sum = 0;
        while(pos > 0)
        {
            sum += nodes[pos];
            pos -= pos & (-pos);
        }
        return sum;
    }
} ft;

void dfsSize(int u, int prev)
{
    s[u] = 1;
    for(Edge e : adj[u])
    {
        int v = e.v;
        ll w = e.w;
        if(v == prev || deleted[v]) continue;
        dfsSize(v, u);
        s[u] += s[v];
    }
}

void dfs(int u, int prev, ll cnt, ll d)
{
    v1.push_back({d, cnt});
    for(Edge e : adj[u])
    {
        int v = e.v;
        ll w = e.w;
        if(v == prev || deleted[v]) continue;
        dfs(v, u, cnt+1, d + w);
    }
}

int getCentroid(int u, int prev, int treeSize)
{
//    if(treeSize == 1) return u;
//    if(s[u] <= treeSize / 2) return prev;
//    int maxS = 0,bestV;
//    for(Edge e: adj[u])
//    {
//        int v = e.v;
//        if(v == prev || deleted[v]) continue;
//        if(s[v] > maxS)
//        {
//            maxS = s[v];
//            bestV = v;
//        }
//    }
//    return getCentroid(bestV,u,treeSize);
    for(Edge e : adj[u])
    {
        int v = e.v;
        if(deleted[v] || v == prev) continue;
        if(s[v] > treeSize / 2) return getCentroid(v, u, treeSize);
    }
    return u;
}

void updateRes(int root)
{
    v2.clear();
    v2.push_back({0,0});
    ll cur = 0;
    for(Edge e : adj[root])
    {
        int u = e.v;
        if(deleted[u]) continue;
        dfs(u, root, 1, e.w);
        sort(all(v1), greater<pll>());
        int j = signed(v1.size()) - 1;
        for(pll p : v1)
        {
            while(j >= 0 && v1[j].fi + p.fi <= x)
            {
                ft.update(v1[j].se + 1, 1);
                j--;
            }
            cur -= ft.query(l - p.se + 1);
        }
        while(j + 1 < signed(v1.size()))
        {
            j++;
            ft.update(v1[j].se + 1, -1);
        }
        while(!v1.empty())
        {
            v2.push_back(v1.back());
            v1.pop_back();
        }
    }
    sort(all(v2), greater<pll>());
    int j = signed(v2.size()) - 1;
    for(pll p : v2)
    {
        while(j >= 0 && v2[j].fi + p.fi <= x)
        {
            ft.update(v2[j].se + 1, 1);
            j--;
        }
        cur += ft.query(l - p.se + 1);
    }
    while(j + 1 < signed(v2.size()))
    {
        j++;
        ft.update(v2[j].se + 1, -1);
    }
    res += cur / 2;
    //cout << root << " " << cur/2 << '\n';
}

void solve(int u)
{
    dfsSize(u, 0);
    int root = getCentroid(u, 0, s[u]);
    deleted[root] = true;
    updateRes(root);
    for(Edge e : adj[root])
    {
        int v = e.v;
        if(deleted[v]) continue;
        solve(v);
    }
}

vector<Edge> adj2[SZ];
bool vis[SZ];

void createTree(int u)
{
    vis[u] = true;
    for(Edge e : adj2[u])
    {
        int v = e.v;
        ll w = e.w;
        if(vis[v]) continue;
        createTree(v);
        adj[u].push_back({v,w});
        //cout << u << " " << v << " " << w << '\n';
    }
}

int main()
{
    init();
    cin >> n >> l >> x;
    for(int i = 2; i <= n; i++)
    {
        int u;
        ll w;
        cin >> u >> w;
        adj[u].push_back({i,w});
        adj[i].push_back({u,w});
        //cout << u << " " << i << " " << w << '\n';
    }
    //createTree(1);
    solve(1);
    cout << res;
}

