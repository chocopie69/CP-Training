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

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 75;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m,k,q;

struct Edge
{
    int v;
    ll w;
    Edge(int _v = 0, ll _w = 0) : v(_v), w(_w) {}
};

vector<Edge> adj[SZ];
ll d[SZ][SZ][SZ], len[SZ][SZ];
bool vis[SZ][SZ];

void dijkstra(int s)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= min(k,n); j++)
        {
            d[s][i][j] = INFLL;
        }
    }
    d[s][s][0] = 0;
    for(int i = 1; i <= min(k,n); i++)
    {
        for(int u = 1; u <= n; u++)
        {
            for(Edge e : adj[u])
            {
                int v = e.v;
                ll w = e.w;
                d[s][v][i] = min(d[s][v][i], d[s][u][i-1] + w);
            }
        }
    }
}

int main()
{
    init();
    cin >> n >> m;
    memset(len, -1, sizeof(len));
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        if(len[u][v] == -1 || w < len[u][v]) len[u][v] = w;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j || len[i][j] == -1) continue;
            adj[i].pb({j, len[i][j]});
        }
    }
    cin >> k >> q;
    for(int u = 1; u <= n; u++)
    {
        dijkstra(u);
    }
    while(q--)
    {
        int u,v;
        cin >> u >> v;
        ll res = INFLL;
        for(int i = 0; i <= min(k,n); i++)
        {
            res = min(res, d[u][v][i]);
        }
        cout << (res == INFLL ? -1 : res) << '\n';
    }
}

