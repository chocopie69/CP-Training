#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "SAVE"

using namespace std;

const int SZ = 1e5+5;
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

ll n,m,u,v,w, res = 0, sumW = 0;
vector<Edge> edges;

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

int main()
{
    init();
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }
    sort(edges.begin(),edges.end(),cmp);
    dsu.init(n);
    for(Edge e : edges)
    {
        u = e.u;
        v = e.v;
        w = e.w;
        sumW += w;
        if(!dsu.joined(u,v))
        {
            dsu.join(u,v);
            res += w;
        }
    }
    cout << sumW - res;
}



