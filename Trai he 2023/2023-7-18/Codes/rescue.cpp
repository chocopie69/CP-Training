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

ll n,m,a,b,dist,u,v,w,d[SZ][2][4][4][4], dir, sa, sb, cntb;
vector<Edge> adj[2][SZ];

struct Node
{
    ll u, dist, dir, sa, sb, cntb;
    Node(ll _u = 0, ll _dist = 0, ll _dir = 0, ll _sa = 0, ll _sb = 0, ll _cntb = 0)
    {
        u = _u;
        dist = _dist;
        dir = _dir;
        sa = _sa;
        sb = _sb;
        cntb = _cntb;
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
            for(int sa = 0; sa <= a; sa++)
            {
                for(int sb = 0; sb <= b; sb++)
                {
                    for(int cntb = 0; cntb <= b; cntb++)
                        d[i][dir][sa][sb][cntb] = INFLL;
                }
            }
        }
    }
    pq.push({1,0,0,0,0,0});
    while(!pq.empty())
    {
        Node cur = pq.top();
        u = cur.u;
        dist = cur.dist;
        dir = cur.dir;
        sa = cur.sa;
        sb = cur.sb;
        cntb = cur.cntb;
        pq.pop();
        if(dist > d[u][dir][sa][sb][cntb]) continue;
        for(Edge e : adj[dir][u])
        {
            v = e.v;
            w = e.w;
            if(d[v][dir][sa][sb][min(cntb + dir,b)] > dist + w)
            {
                d[v][dir][sa][sb][min(cntb + dir,b)] = dist + w;
                pq.push({v,dist + w ,dir, sa, sb, min(cntb + dir,b)});
            }
            if(dir == 0 && sa < a && d[v][dir][sa+1][sb][cntb] > dist)
            {
                d[v][dir][sa+1][sb][cntb] = dist;
                pq.push({v,dist ,dir, sa + 1, sb, cntb});
            }
            if(dir == 1 && sb < b && d[v][dir][sa][sb+1][min(cntb + dir,b)] > dist + w*2LL)
            {
                d[v][dir][sa][sb+1][min(cntb + dir,b)] = dist + w*2LL;
                pq.push({v,dist + w*2LL ,dir, sa, sb + 1, min(cntb + dir,b)});
            }
        }
        if(dir == 0)
        {
            for(Edge e : adj[1][u])
            {
                v = e.v;
                w = e.w;
                if(d[v][1][sa][sb][min(cntb + 1,b)] > dist + w)
                {
                    d[v][1][sa][sb][min(cntb + 1,b)] = dist + w;
                    pq.push({v,dist + w ,1, sa, sb, min(cntb + 1,b)});
                }
                if(sb < b && d[v][1][sa][sb+1][min(cntb + 1,b)] > dist + w*2LL)
                {
                    d[v][1][sa][sb+1][min(cntb + 1,b)] = dist + w*2LL;
                    pq.push({v,dist + w*2LL ,1, sa, sb + 1, min(cntb + 1,b)});
                }
            }
        }
    }
    for(int i = 2; i <= n; i++)
    {
        ll res = INFLL;
        for(int sa = 0; sa <= a; sa++)
        {
            for(int sb = 0; sb <= b; sb++)
            {
                res = min({ res,d[i][0][sa][sb][sb], d[i][1][sa][sb][sb] });
            }
        }
        cout << (res == INFLL ? -1 : res) << " ";
    }
}

