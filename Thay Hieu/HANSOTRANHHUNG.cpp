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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m, t[SZ];

struct Edge
{
    int v;
    ll w;
    Edge(int _v = 0 , ll _w = 0) : v(_v), w(_w) {}
};

vector<Edge> adj[SZ];

struct Node
{
    int u;
    ll dist;

    Node(int _u = 0, ll _dist = 0) : u(_u), dist(_dist) {}

    bool operator < (const Node& other) const
    {
        return dist > other.dist;
    }
};

priority_queue<Node> pq;
ll d[SZ];

void dijkstra()
{
    while(!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();
        int u = cur.u;
        ll dist = cur.dist;
        if(d[u] < dist) continue;
        for(Edge e : adj[u])
        {
            int v = e.v;
            ll w = e.w;
            if(t[v] == -1) continue;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({v, d[v]});
            }
        }
    }
}

bool vis[SZ], deleted[SZ];

void dfs(int u, ll mdist)
{
    vis[u] = true;
    if(d[u] <= mdist && t[u] == 0)
    {
        deleted[u] = true;
        return;
    }
    for(Edge e : adj[u])
    {
        int v = e.v;
        if(!vis[v]) dfs(v,mdist);
    }
}

void dfs2(int u)
{
    vis[u] = true;
    for(Edge e : adj[u])
    {
        int v = e.v;
        if(!vis[v] && !deleted[v]) dfs2(v);
    }
}

bool check(ll res)
{
    memset(vis, false, sizeof(vis));
    memset(deleted, false, sizeof(deleted));
    for(int i = 1; i <= n; i++)
    {
        if(t[i] != -1 || vis[i]) continue;
        dfs(i,res);
    }
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; i++)
    {
        //if(deleted[i]) cout << i << '\n';
    }
    for(int i = 1; i <= n; i++)
    {
        if(t[i] != 1 || vis[i]) continue;
        dfs2(i);
        break;
    }
    for(int i = 1; i <= n; i++)
    {
        if( (t[i] == 1 && !vis[i]) || (t[i] == -1 && vis[i]) ) return false;
    }
    return true;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i = 1; i <= n; i++)
    {
        d[i] = (t[i] == 1 ? 0 : INFLL);
        if(t[i] == 1)
        {
            pq.push({i,0});
        }
    }
    dijkstra();
    ll lo = 0, hi = 1e18, mid;
    bool flag = false;
    ll res = -1;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(check(mid))
        {
            flag = true;
            res = mid;
            hi = mid-1;
        } else
        {
            lo = mid+1;
        }
    }
    cout << res;
    //cout << '\n' << check(3);
}
/*
7 8
1 0 1 0 0 0 0
1 2 1
2 3 3
1 4 2
2 5 2
6 4 6
6 5 4
7 5 1
6 7 1
*/
