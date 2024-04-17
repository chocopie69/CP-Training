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

const int SZ = 1e3+5, SZ2 = 5e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,k;

struct Edge
{
    int v;
    ll p,q;
    Edge(int _v = 0, ll _p = 0, ll _q = 0)
    {
        v = _v;
        p = _p;
        q = _q;
    }
};

struct FullEdge
{
    int u,v;
    ll p,q;
    FullEdge(int _u = 0, int _v = 0, ll _p = 0, ll _q = 0)
    {
        u = _u;
        v = _v;
        p = _p;
        q = _q;
    }
};

vector<Edge> adj[SZ];
FullEdge edges[SZ2];

ll d[SZ];

struct Node
{
    int u;
    ll dist;
    Node(int _u = 0, ll _dist = 0)
    {
        u = _u;
        dist = _dist;
    }
    bool operator < (const Node& other) const
    {
        return dist > other.dist;
    }
};

priority_queue<Node> pq;

pii queries[11];
ll res[11];

void dijkstra(int i, int s, int s2, int mx, ll val)
{
    pq.push({s,0});
    pq.push({s2,0});
    for(int u = 1; u <= n; u++)
    {
        d[u] = INFLL;
    }
    d[s] = 0;
    d[s2] = 0;
    while(!pq.empty())
    {
        int u = pq.top().u;
        ll dist = pq.top().dist;
        pq.pop();
        if(dist > d[u]) continue;
        for(Edge e : adj[u])
        {
            int v = e.v;
            ll p = e.p, q = e.q;
            if(q-p > mx) continue;
            if(d[v] > dist + p)
            {
                d[v] = dist + p;
                pq.push({v,dist + p});
            }
        }
    }
    for(int i = 1; i <= k; i++)
    {
        int s = queries[i].fi, t = queries[i].se;
        res[i] = min(res[i], d[s] + d[t] + val);
    }
}

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        ll p,q;
        cin >> u >> v >> p >> q;
        edges[i] = {u,v,p,q};
        adj[u].push_back({v,p,q});
        adj[v].push_back({u,p,q});
    }
    for(int i = 1; i <= k; i++)
    {
        int s,t;
        cin >> s >> t;
        queries[i].fi = s;
        queries[i].se = t;
        res[i] = INFLL;
    }
    for(int i = 1; i <= m; i++)
    {
        int u = edges[i].u, v = edges[i].v, p = edges[i].p, q = edges[i].q;
        dijkstra(i,u,v,q-p,q);
    }
    for(int i = 1; i <= k; i++)
    {
        cout << res[i] << '\n';
    }
}

/*
4 5 1
1 2 2 3
1 3 8 10
1 4 3 4
3 4 4 6
2 3 1 12
2 4
*/
