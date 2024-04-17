#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BKLR"

using namespace std;

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,k,a[SZ], s, t;

struct Edge
{
    ll v, w;
    Edge(ll _v = 0, ll _w = 0) : v(_v), w(_w) {}
};

vector<Edge> adj[SZ];

struct Node
{
    ll u, dist;
    Node(ll _u = 0, ll _dist = 0)
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
ll d[SZ];

namespace sub1
{
    void solve()
    {
        for(int i = 1; i <= n; i++)
        {
            d[i] = INFLL;
        }
        d[s] = 0;
        pq.push({s,0});
        while(!pq.empty())
        {
            Node cur = pq.top();
            pq.pop();
            ll u = cur.u, dist = cur.dist;
            if(dist > d[u]) continue;
            for(Edge e : adj[u])
            {
                ll v = e.v, w = e.w;
                if(d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                    pq.push({v, d[v] });
                }
            }
            for(int j = 1; j <= n; j++)
            {
                if(d[j] > d[u] + (a[u] + a[j]) % k )
                {
                    d[j] = d[u] + (a[u] + a[j]) % k;
                    pq.push({j, d[j]});
                }
            }
        }
        cout << d[t];
    }
}

namespace sub2
{

    ll h[SZ], d[SZ], up[SZ][19];

    void dfs(int u) {
        for (Edge e : adj[u]) {
            ll v = e.v, w = e.w;
            if (v == up[u][0]) continue;

            h[v] = h[u] + 1;
            d[v] = d[u] + w;

            up[v][0] = u;
            for (int j = 1; j <= 18; ++j)
                up[v][j] = up[up[v][j - 1]][j - 1];

            dfs(v);
        }
    }

    int lca(int u, int v) {
        if (h[u] != h[v]) {
            if (h[u] < h[v]) swap(u, v);

            int k = h[u] - h[v];
            for (int j = 0; (1 << j) <= k; ++j)
                if (k >> j & 1)
                    u = up[u][j];
        }
        if (u == v) return u;

        int k = __lg(h[u]);
        for (int j = k; j >= 0; --j)
            if (up[u][j] != up[v][j])
                u = up[u][j], v = up[v][j];
        return up[u][0];
    }

    ll dist(int u, int v)
    {
        return d[u] + d[v] - 2*d[lca(u,v)];
    }

    void solve()
    {
        dfs(1);
        ll mn = INFLL;
        for(int i = 1; i <= n; i++)
        {
            mn = min(mn, a[i] + dist(i,t));
        }
        ll res = dist(s,t);
        for(int i = 1; i <= n; i++)
        {
            res = min(res, dist(s,i) + a[i] + mn );
        }
        cout << res;
    }
}

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> s >> t;
    if(n <= 2000)
        sub1::solve();
    else if(m == n-1)
        sub2::solve();
}

/*
7 6 100000
1 2 3
1 3 2
3 4 3
4 5 2
4 6 4
6 7 3
1 2 3 3 3 9 5
1 6
*/
