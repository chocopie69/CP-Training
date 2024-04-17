#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "MAP"

using namespace std;

const int SZ = 2e3+5;
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
    ll v, w, t;
    Edge(ll _v, ll _w, ll _t)
    {
        v = _v;
        w = _w;
        t = _t;
    }
};

struct Node
{
    ll u, d, cnt;
    Node(ll _u, ll _d, ll _cnt)
    {
        u = _u;
        d = _d;
        cnt = _cnt;
    }
};

ll u,v,w,t,n,m,cnt, d[SZ][SZ], res = INFLL;
vector<Edge> adj[SZ];
bool vis[SZ];

struct cmp
{
    bool operator() (Node x, Node y)
    {
        return x.d > y.d;
    }
};

priority_queue<Node, vector<Node>, cmp> pq;

int main()
{
    init();
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v >> w >> t;
        adj[u].push_back({v,w,t});
        adj[v].push_back({u,w,t});
    }
    for(int i = 1; i < SZ; i++)
    {
        for(int j = 0; j < SZ; j++)
        {
            d[i][j] = INFLL;
        }
    }
    d[1][0] = 0;
    pq.push({1,0,0});
    while(!pq.empty())
    {
        u = pq.top().u;
        cnt = pq.top().cnt;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(Edge e : adj[u])
        {
            v = e.v;
            w = e.w;
            //cout << d[v][cnt+1] << " " << d[u][cnt] + w + t*cnt << " " << cnt << " " << v << '\n';
            t = e.t;
            if(d[v][cnt+1] > d[u][cnt] + w + t*cnt)
            {
                d[v][cnt+1] = d[u][cnt] + w + t*cnt;
                pq.push({v,d[v][cnt+1],cnt+1});
            }
        }
    }
    for(int i = 0; i <= n; i++)
    {
        res = min(res, d[n][i]);
        //cout << i << " " << d[n][i] << '\n';
    }
    cout << (res == INFLL ? -1 : res);
}

