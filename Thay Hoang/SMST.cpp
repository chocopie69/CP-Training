#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "SMST"

using namespace std;

const int SZ = 1e5+5;
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
    ll u, v, w;

    Edge(ll _u, ll _v, ll _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};

ll n,m,u,v,w, res = 0, cntEdge = 0, mstW = 0;

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

struct cmp
{
    bool operator() (Edge x, Edge y)
    {
        return x.w < y.w;
    }
};

set<Edge, cmp> edges;
//vector<Edge> edges;

void kruskal()
{
    dsu.init(n);
    cntEdge = 0;
    mstW = 0;
    auto delPos = edges.end();
    for(auto it = edges.begin(); it != edges.end(); it++)
    {
        Edge e = *it;
        u = e.u;
        v = e.v;
        w = e.w;
        if(dsu.joined(u,v))
        {
            delPos = it;
            continue;
        }
        dsu.join(u,v);
        cntEdge++;
        mstW += w;
        if(cntEdge == n-1) break;
    }
    if(delPos != edges.end()) edges.erase(delPos);
    if(cntEdge < n-1)  mstW = 123456789;
}

int main()
{
    init();
    cin >> n >> m;
    dsu.init(n);
    while(m--)
    {
        cin >> u >> v >> w;
        edges.insert({u,v,w});
        kruskal();
        cout << mstW << '\n';
    }
}


