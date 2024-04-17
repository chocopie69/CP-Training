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

#define TASKNAME "TRANSPORT"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin);
    ///freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

struct Edge
{
    int v;
    ll w;
    Edge(int _v = 0, ll _w = 0) : v(_v), w(_w) {}
};

int n, s[SZ];
bool deleted[SZ];
ll a[SZ], res = 0;
vector<Edge> adj[SZ];

void dfsSize(int u, int p)
{
    s[u] = 1;
    for(Edge e : adj[u])
    {
        int v = e.v;
        if(v == p || deleted[v]) continue;
        dfsSize(v, u);
        s[u] += s[v];
    }
}

int centroid(int u, int p, int treeSize)
{
    for(Edge e : adj[u])
    {
        int v = e.v;
        if(deleted[v] || v == p) continue;
        if(s[v] > treeSize / 2) return centroid(v, u, treeSize);
    }
    return u;
}

vector<ll> v1, v2, v3, v4;

void dfs(int u, int p, ll x, ll k, ll y, ll mn)
{
    v1.pb(-k);
    if(k >= 0) res++;
    if(mn >= 0)
    {
        v2.pb(y);
        //cout << u << " - " << y << '\n';
        res++;
    }
    for(Edge e : adj[u])
    {
        int v = e.v;
        ll w = e.w;
        if(deleted[v] || v == p) continue;
        dfs(v, u, x + a[u] - w, min(k, x + a[u] - w), y + a[v] - w, min(0LL, mn + a[v] - w));
    }
}

void updateRes(int root)
{
    v3.clear();
    v4.clear();
    for(Edge e : adj[root])
    {
        int v = e.v;
        ll w = e.w;
        if(deleted[v]) continue;
        dfs(v, root, a[root] - w, min(0LL, a[root] - w), a[v] - w, min(0LL,a[v] - w));
        sort(all(v1));
        sort(all(v2));
        for(ll x : v2)
        {
            int pos = upper_bound(all(v1), x) - v1.begin() - 1;
            res -= (pos + 1);
        }
        while(!v1.empty())
        {
            v3.pb(v1.back());
            v1.pop_back();
        }
        while(!v2.empty())
        {
            v4.pb(v2.back());
            v2.pop_back();
        }
    }
    sort(all(v3));
    sort(all(v4));
//    if(root == 5)
//    {
//        for(ll x : v4)
//        {
//            cout << x << " ";
//        }
//        cout << '\n';
//        for(ll x : v3)
//        {
//            cout << x << " ";
//        }
//        cout << '\n';
//    }
    for(ll x : v4)
    {
        int pos = upper_bound(all(v3), x) - v3.begin() - 1;
        res += (pos + 1);
    }
}

void solve(int u)
{
    dfsSize(u, 0);
    int root = centroid(u, 0, s[u]);
    deleted[root] = true;
    ll preres = res;
    updateRes(root);
    //cout << root << " " << res-preres << '\n';
    for(Edge e : adj[root])
    {
        int v = e.v;
        if(deleted[v]) continue;
        solve(v);
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    solve(1);
    cout << res;
}

