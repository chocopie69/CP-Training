#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n, num[SZ], tail[SZ];

struct Edge
{
    int u,v;
    ll w;
    Edge(int _u = 0, int _v = 0, ll _w = 0) : u(_u), v(_v), w(_w) {}

    bool operator < (const Edge& other) const
    {
        return w > other.w;
    }
};

vector<Edge> edges;
vector<int> adj[SZ];
int timer = 0, tour[SZ];
ll b[SZ];

void dfs(int u, int pre)
{
    num[u] = ++timer;
    tour[timer] = u;
    for(int v : adj[u])
    {
        if(v != pre) dfs(v, u);
    }
    tail[u] = timer;
}

int main()
{
    init();
    cin >> n;
    ll sum = 0;
    for(int i = 1; i < n; i++)
    {
        int u,v;
        ll c,d;
        cin >> u >> v >> c >> d;
        sum += c+d;
        adj[u].pb(v);
        adj[v].pb(u);
        edges.pb({u,v,c});
        edges.pb({v,u,d});
    }
    dfs(1,0);
    for(Edge e : edges)
    {
        int u = e.u, v = e.v;
        ll w = e.w;
        if(num[u] < num[v])
        {
            int lo = num[v], hi = tail[v];
            b[1] += w;
            b[lo] -= w;
            b[hi+1] += w;
            b[n+1] -= w;
        } else
        {
            int lo = num[u], hi = tail[u];
            b[lo] += w;
            b[hi+1] -= w;
        }
    }
    for(int i = 1; i <= n; i++)
    {

    }
}

