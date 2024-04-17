#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "BWGRAPH"

using namespace std;

const int SZ = 1e6+5;
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
    ll u, v, w, id;

    Edge(ll _u, ll _v, ll _w, ll _id)
    {
        u = _u;
        v = _v;
        w = _w;
        id = _id;
    }
};

ll n,m,u,v,w, res = 0;
vector<Edge> edges;
bool inTree[SZ], flag = true;

bool cmp(Edge x, Edge y)
{
    return x.w > y.w;
}

struct DSU
{
    ll par[SZ], s[SZ];
    void init(int n)
    {
        memset(s,0,sizeof(s));
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
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        edges.push_back({u,v,w,i});
    }
    sort(edges.begin(),edges.end(),cmp);
    dsu.init(n);
    flag = true;
    ll cntEdge = 0;
    for(Edge e : edges)
    {
        u = e.u;
        v = e.v;
        w = e.w;
        ll id = e.id;
        if(w == 2) continue;
        if(!dsu.joined(u,v))
        {
            dsu.join(u,v);
            cntEdge++;
            inTree[id] = true;
            res++;
        }
    }
    if(cntEdge < n-1) flag = false;
    cntEdge = 0;
    dsu.init(n);
    for(Edge e : edges)
    {
        u = e.u;
        v = e.v;
        w = e.w;
        ll id = e.id;
        if(w == 1) continue;
        if(!dsu.joined(u,v))
        {
            dsu.join(u,v);
            cntEdge++;
            if(inTree[id]) continue;
            res++;
            inTree[id] = true;
        }
    }
    if(cntEdge < n-1) flag = false;
    if(!flag)
    {
        cout << -1;
        return 0;
    }
    cout << m-res << '\n';
    for(int i = 1; i <= m; i++)
    {
        if(!inTree[i]) cout << i << " ";
    }
}

/*
5 7
1 2 3
2 3 3
3 4 3
5 3 2
5 4 1
5 2 2
1 5 1
*/



