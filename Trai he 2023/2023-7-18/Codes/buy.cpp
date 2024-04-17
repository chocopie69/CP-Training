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

ll n,m,a[SZ],u,v,w,dist,d[SZ];

struct Edge
{
    ll v, w;
    Edge(ll _v = 0, ll _w = 0)
    {
        v = _v;
        w = _w;
    }
};

struct Node
{
    ll u, dist;
    Node(ll _u = 0, ll _dist = 0)
    {
        u = _u;
        dist = _dist;
    }
};

struct cmp
{
    bool operator () (Node x, Node y)
    {
        return x.dist > y.dist;
    }
};

priority_queue<Node,vector<Node>,cmp> pq;
vector<Edge> adj[SZ];

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        adj[0].push_back({i,a[i]});
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v,w*2});
        adj[v].push_back({u,w*2});
    }
    for(int i = 1; i <= n; i++)
    {
        d[i] = INFLL;
    }
    d[0] = 0;
    pq.push({0,0});
    while(!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();
        u = cur.u;
        dist = cur.dist;
        if(dist > d[u]) continue;
        for(Edge e : adj[u])
        {
            v = e.v;
            w = e.w;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({v,d[v]});
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << d[i] << ' ';
    }
}
