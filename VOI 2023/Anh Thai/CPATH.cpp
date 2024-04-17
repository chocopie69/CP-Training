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

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

struct Edge
{
    int v, c;
    Edge(int _v = 0, int _c = 0) : v(_v), c(_c) {}
};

int n,m, d[SZ], added[SZ];
vector<Edge> adj[SZ], child[SZ];
vector<int> v1;
vector<pii> v2;
queue<int> qu;
bool vis[SZ];

void bfs(int s)
{
    qu.push(s);
    d[s] = 0;
    vis[s] = true;
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for(Edge e : adj[u])
        {
            int v = e.v, c = e.c;
            if(!vis[v] || d[v] == d[u] + 1)
            {
                child[v].push_back({u,c});
                if(vis[v]) continue;
                qu.push(v);
                vis[v] = true;
                d[v] = d[u] + 1;
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
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    bfs(n);
    cout << d[1] << '\n';
    v1.push_back(1);
    int timer = 0;
    while(true)
    {
        ++timer;
        int mn = INF;
        while(!v1.empty())
        {
            int u = v1.back();
            v1.pop_back();
            if(u == n) return 0;
            for(Edge e : child[u])
            {
                int v = e.v, c = e.c;
                v2.push_back({v, c});
                mn = min(mn, c);
            }
        }
        cout << mn << " ";
        while(!v2.empty())
        {
            pii p = v2.back();
            v2.pop_back();
            int u = p.fi, c = p.se;
            if(added[u] == timer) continue;
            if(c == mn)
            {
                v1.push_back(u);
                added[u] = timer;
            }
        }
    }
}
