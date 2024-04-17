#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "HIGHWAY"

using namespace std;

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Edge
{
    ll u, v, w;

    Edge(ll _u, ll _v, ll _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};

ll n,m,u,v,w, res = 0;
bool vis[SZ][SZ];
pll a[SZ];
vector<Edge> edges, edgesRes;

bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}

struct DSU
{
    ll par[SZ], s[SZ];

    void init(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            par[i] = i;
            s[i] = 1;
        }
    }

    ll get(ll u)
    {
        return (par[u] == u ? u : par[u] = get(par[u]));
    }

    void join(ll u, ll v)
    {
        u = get(u);
        v = get(v);
        if(u == v) return;
        if(s[u] > s[v]) swap(u,v);
        par[v] = u;
        s[v] += s[u];
    }

    bool joined(ll u, ll v)
    {
        u = get(u);
        v = get(v);
        return u == v;
    }
} dsu;

ll dist(ll xi, ll yi , ll xj, ll yj)
{
    return abs(xi - xj) * abs(xi - xj) + abs(yi - yj) * abs(yi-yj);
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            edges.push_back({i,j,dist(a[i].fi, a[i].se, a[j].fi, a[j].se)});
        }
    }
    dsu.init(n);
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        if(u > v) swap(u,v);
        vis[u][v] = true;
        dsu.join(u,v);
    }
    sort(edges.begin(),edges.end(),cmp);
    for(Edge e : edges)
    {
        u = e.u;
        v = e.v;
        w = e.w;
        //cout << u << " " << v << " " << w << '\n';
        if(!dsu.joined(u,v))
        {
            dsu.join(u,v);
            if(!vis[u][v])
            {
                res++;
                edgesRes.push_back(e);
            }
        }
    }
    cout << res << '\n';
    for(Edge e : edgesRes)
    {
        cout << e.u << " " << e.v << '\n';
    }
}


