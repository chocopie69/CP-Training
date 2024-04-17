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

int n, a[SZ], b[SZ], p[SZ];
ll z[SZ], cur = 0;
vector<ll> res;

struct Edge
{
    int v;
    ll w;
    Edge(int _v = 0, ll _w = 0) : v(_v), w(_w) {}
};
vector<Edge> adj[SZ];

struct DSU
{
    ll par[SZ], s[SZ], path[SZ], vis[SZ];

    map<ll, ll> mp[SZ];
    vector<ll> vec;

    void init(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            par[i] = i;
            s[i] = 1;
            mp[i][0] = 1;
            path[i] = 0;
        }
    }

    int get(ll u)
    {
        return (par[u] == u ? u : par[u] = get(par[u]));
    }

    void dfs(int p, int u, int id, ll d)
    {
        cur += mp[p][d];
        vec.pb(d);
        vis[u] = id;
        path[u] = d;
        for(Edge e : adj[u])
        {
            int v = e.v;
            ll w = e.w;
            if(vis[v] == id) continue;
            dfs(p, v, id, d ^ w);
        }
    }

    void join(int u, int v, ll w, int id)
    {
        int u1 = get(u);
        int v1 = get(v);
        if(u1 == v1) return;
        if(s[u1] < s[v1])
        {
            swap(u1, v1);
            swap(u, v);
        }
        dfs(u1, v, id, path[u] ^ w);
        while(!vec.empty())
        {
            mp[u1][vec.back()]++;
            vec.pop_back();
        }
        par[v1] = u1;
        s[u1] += s[v1];
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
} dsu;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        cin >> a[i] >> b[i] >> z[i];
    }
    for(int i = 1; i < n; i++)
    {
        cin >> p[i];
    }
    dsu.init(n);
    res.pb(0);
    for(int i = n-1; i >= 1; i--)
    {
        dsu.join(a[p[i]], b[p[i]], z[p[i]], i);
        res.pb(cur);
    }
    while(!res.empty())
    {
        cout << res.back() << '\n';
        res.pop_back();
    }
}

/*
8
1 5 3
1 2 6
2 3 6
3 4 7
4 6 7
6 7 3
3 8 3
2 3 1 7 5 4 6
*/

