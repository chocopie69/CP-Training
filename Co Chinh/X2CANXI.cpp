#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "X2CANXI"

using namespace std;

const int SZ = 250+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct cmp
{
    bool operator() (pll x, pll y)
    {
        return x.se > y.se;
    }
};

struct Edge
{
    ll u,v,w;

    Edge(ll _u, ll _v, ll _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};

ll n,m,u,v,w, d[SZ], res = 0, pre;
set<pll> adj[SZ];
vector<Edge> edges;
priority_queue<pll, vector<pll>, cmp> pq;

ll getMinDist()
{
    for(int i = 1; i <= n; i++)
    {
        d[i] = INFLL;
    }
    d[1] = 0;
    pq.push({1,0});
    while(!pq.empty())
    {
        ll u = pq.top().fi, curW = pq.top().se;
        pq.pop();
        if(curW > d[u]) continue;
        for(pll e : adj[u])
        {
            ll v = e.fi, w = e.se;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({v,d[v]});
            }
        }
    }
    return (d[n] == INFLL ? -1 : d[n]);
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
        adj[u].insert({v,w});
        adj[v].insert({u,w});
    }
    pre = getMinDist();
    for(Edge e : edges)
    {
        u = e.u;
        v = e.v;
        w = e.w;
        adj[u].erase({v,w});
        adj[v].erase({u,w});
        adj[u].insert({v,w*2});
        adj[v].insert({u,w*2});
        res = max(res, getMinDist() - pre);
        adj[u].erase({v,w*2});
        adj[v].erase({u,w*2});
        adj[u].insert({v,w});
        adj[v].insert({u,w});
    }
    cout << res;
}

