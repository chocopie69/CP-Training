#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "Bai5"

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

int n, m;

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
        if(s[u] < s[v]) swap(u,v);
        par[v] = u;
        s[u] += s[v];
    }

    bool joined(ll u, ll v)
    {
        u = get(u);
        v = get(v);
        return u == v;
    }
} dsu;

struct Coord
{
    ld x,y;
    Coord(ld _x = 0, ld _y = 0)
    {
        x = _x;
        y = _y;
    }
};

struct Edge
{
    ll u,v;
    ld w;
    Edge(ll _u = 0, ll _v = 0, ld _w = 0)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};

bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}

double dist(Coord u, Coord v)
{
    ld distx = abs(u.x - v.x), disty = abs(u.y - v.y);
    return hypot(distx,disty);
}

Coord a[SZ];
vector<Edge> edges;

double res = 0;

int main()
{
    init();
    cin >> n;
    dsu.init(n);
    for(int i = 1; i <= n; i++)
    {
        ld x,y;
        cin >> x >> y;
        a[i] = {x,y};
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        dsu.join(u,v);
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            edges.push_back({i,j, dist(a[i],a[j]) });
        }
    }
    sort(all(edges),cmp);
    for(Edge e : edges)
    {
        int u = e.u, v = e.v;
        ld w = e.w;
        if(dsu.joined(u,v)) continue;
        dsu.join(u,v);
        res += w;
    }
    cout << (ll) (res);
}

/*
5
1 5
0 0
3 2
4 5
5 1
1
1 4
*/
