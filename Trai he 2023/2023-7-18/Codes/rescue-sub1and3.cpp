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

struct Edge
{
    ll v,w;
    Edge(ll _v = 0, ll _w = 0)
    {
        v = _v;
        w = _w;
    }
};

ll n,m,a,b,dist,u,v,w,d[2][SZ], dir;
vector<Edge> adj[2][SZ];

struct Node
{
    ll u, dist, dir;
    Node(ll _u = 0, ll _dist = 0, ll _dir = 0)
    {
        u = _u;
        dist = _dist;
        dir = _dir;
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

int main()
{
    init();
    cin >> n >> m >> a >> b;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        adj[0][u].push_back({v,w});
        adj[1][v].push_back({u,w});
    }
    for(int i = 1; i <= n; i++)
    {
        for(int dir = 0; dir <= 1; dir++)
        {
            d[dir][i] = INFLL;
        }
    }
    pq.push({1,0,0});
    while(!pq.empty())
    {
        Node cur = pq.top();
        u = cur.u;
        dist = cur.dist;
        dir = cur.dir;
        pq.pop();
        if(dist > d[dir][u]) continue;
        for(Edge e : adj[dir][u])
        {
            v = e.v;
            w = e.w;
            if(d[dir][v] > dist + w)
            {
                d[dir][v] = dist + w;
                pq.push({v,d[dir][v],dir});
            }
        }
        if(dir == 0)
        {
            for(Edge e : adj[1][u])
            {
                v = e.v;
                w = e.w;
                if(d[1][v] > dist + w)
                {
                    d[1][v] = dist + w;
                    pq.push({v,d[1][v],1});
                }
            }
        }
    }
    for(int i = 2; i <= n; i++)
    {
        ll res = min(d[0][i],d[1][i]);
        cout << (res == INFLL ? -1 : res) << " ";
    }
}
