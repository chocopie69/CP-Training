#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "JAMONE"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin);
    //freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Edge
{
    ll v,p,q;
    Edge(ll _v = 0, ll _p = 0, ll _q = 0)
    {
        v = _v;
        p = _p;
        q = _q;
    }
};

struct Node
{
    ll u, dist, sb, mx;
    Node(ll _u = 0, ll _dist = 0, ll _sb = 0, ll _mx = 0)
    {
        u = _u;
        dist = _dist;
        sb = _sb;
        mx = _mx;
    }
};

struct cmp
{
    bool operator () (Node x, Node y)
    {
        if(x.dist != y.dist)
        {
            return x.dist > y.dist;
        }
        if(x.sb != y.sb)
        {
            return x.sb < y.sb;
        }
        if(x.sb == 0)
        {
            return x.mx > y.mx;
        }
        return x.mx < y.mx;
    }
};

ll n,m,k, d[SZ][2], check0[SZ], check1[SZ];
vector<Edge> adj[SZ];
priority_queue<Node,vector<Node>,cmp> pq;

ll dijkstra(ll s, ll t)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= 1; j++)
        {
            d[i][j] = INFLL;
        }
    }
    d[s][0] = 0;
    d[s][1] = 0;
    while(!pq.empty())
        pq.pop();
    pq.push({s,0,0,0});
    for(int i = 1; i <= n; i++)
    {
        check0[i] = -1;
        check1[i] = -1;
    }
    while(!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();
        ll u = cur.u, dist = cur.dist, sb = cur.sb, mx = cur.mx;
        if(u == t && sb == 1) return dist;
        if(sb == 0 && check0[u] != -1 && mx >= check0[u]) continue;
        if(sb == 0) check0[u] = mx;
        if(check1[u] != -1 && mx <= check1[u]) continue;
        if(sb == 1) check1[u] = mx;
        for(Edge e : adj[u])
        {
            ll v = e.v, p = e.p, q = e.q;
            if(sb == 0 || q-p <= mx )
            {
                d[v][sb] = dist + p;
                pq.push({v,dist + p, sb,max(mx,q-p) });
            }
            if(q-p >= mx && sb == 0)
            {
                d[v][sb+1] = dist + q;
                pq.push({v,dist + q, sb+1,q-p});
            }
        }
    }
    //return d[t][1];
}

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        ll u,v,p,q;
        cin >> u >> v >> p >> q;
        adj[u].push_back({v,p,q});
        adj[v].push_back({u,p,q});
    }
    while(k--)
    {
        ll s,t;
        cin >> s >> t;
        cout << dijkstra(s,t) << '\n';
    }
}

/*
6 6 2
1 2 3 5
1 3 6 10
2 3 2 9
3 5 4 6
2 4 4 9
4 6 9 10
5 6
2 4
*/
