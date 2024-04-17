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

const int SZ = 1e3+5;
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
    ll w;
    Edge(int _v = 0, ll _w = 0)
    {
        v = _v;
        w = _w;
    }
};

vector<Edge> adj[SZ];

struct Node
{
    int u;
    ll dist;
    Node(int _u = 0, ll _dist = 0)
    {
        u = _u;
        dist = _dist;
    }
};

struct cmp
{
    bool operator() (Node x, Node y)
    {
        return x.dist > y.dist;
    }
};

priority_queue<Node, vector<Node>, cmp> pq;

int cnt[SZ];
ll d[SZ][105];
vector<ll> v;

bool vis[SZ];

void dfs(int u)
{
    vis[u] = true;
    for(Edge e : adj[u])
    {
        int v = e.v;
        if(!vis[v]) dfs(v);
    }
}

bool check()
{
    dfs(1);
    return vis[n];
}

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
//    if(!check())
//    {
//        cout << -1;
//        return 0;
//    }
    pq.push({1,0});
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            d[i][j] = INFLL;
        }
    }
    d[1][0] = 0;
    while(cnt[n] < k && !pq.empty())
    {
        Node cur = pq.top();
        pq.pop();
        int u = cur.u;
        ll dist = cur.dist;
        //cout << u << " " << dist << '\n';
        if(cnt[u] == k) continue;
        if(d[u][cnt[u]] != dist)
        {
            cnt[u]++;
            d[u][cnt[u]] = dist;
        }
        for(Edge e : adj[u])
        {
            int v = e.v;
            ll w = e.w;
            pq.push({v, dist + w});
        }
    }
    for(int i = 1; i <= k; i++)
    {
        if(d[n][i] == INFLL)
        {
            cout << -1;
            return 0;
        }
    }
    for(int i = 1; i <= k; i++)
    {
        cout << d[n][i] << " ";
    }
}
