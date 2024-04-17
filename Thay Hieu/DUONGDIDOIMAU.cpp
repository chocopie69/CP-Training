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

ll d[SZ][2];
int n,m;

struct Node
{
    int u;
    ll dist;
    int color;
    Node(int _u = 0, ll _dist = 0, int _color = 0)
    {
        u = _u;
        dist = _dist;
        color = _color;
    }
};

struct cmp
{
    bool operator() (Node x, Node y)
    {
        return x.dist > y.dist;
    }
};

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

vector<Edge> adj[2][SZ];

priority_queue<Node, vector<Node>, cmp> pq;

void dijkstra()
{
    for(int i = 1; i <= n; i++)
    {
        d[i][0] = INFLL;
        d[i][1] = INFLL;
    }
    d[1][0] = 0;
    d[1][1] = 0;
    pq.push({1,0,0});
    pq.push({1,0,1});
    while(!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();
        int u = cur.u, color = cur.color;
        ll dist = cur.dist;
        if(dist > d[u][color]) continue;
        int ncolor = 1 - color;
        for(Edge e : adj[ncolor][u])
        {
            int v = e.v;
            ll w = e.w;
            if(d[v][ncolor] > d[u][color] + w)
            {
                d[v][ncolor] = d[u][color] + w;
                pq.push({v, d[v][ncolor], ncolor});
            }
        }
    }
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v,c;
        ll k;
        cin >> u >> v >> k >> c;
        adj[c][u].push_back({v,k});
        adj[c][v].push_back({u,k});
    }
    dijkstra();
    ll res = min(d[n][0], d[n][1]);
    if(res != INFLL)
    {
        cout << res;
    } else
    {
        cout << -1;
    }
}
