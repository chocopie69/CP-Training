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

const int SZ = 3e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m, h[SZ], minH[SZ], up[SZ][20];
vector<int> adj[SZ];
pii a[SZ];

void dfs(int u, int prev)
{
    for(int v : adj[u])
    {
        if(v == prev) continue;
        h[v] = h[u] + 1;
        up[v][0] = u;
        for(int j = 1; j < 20; j++)
        {
            up[v][j] = up[up[v][j-1]][j-1];
        }
        dfs(v,u);
    }
}

int lca(int u, int v)
{
    if(h[u] != h[v])
    {
        if(h[u] < h[v]) swap(u,v);
        int diff = h[u] - h[v];
        for(int j = 0; j < 20; j++)
        {
            if(diff >> j & 1) u = up[u][j];
        }
    }
    if(u == v) return u;
    for(int j = 19; j >= 0; j--)
    {
        if(up[u][j] != up[v][j])
        {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

void dfs2(int u, int prev)
{
    for(int v : adj[u])
    {
        if(v == prev) continue;
        dfs2(v,u);
        //cout << u << " - " << v << '\n';
        minH[u] =  min(minH[u], minH[v]);
    }
}

struct Edge
{
    int v,w;
    Edge(int _v = 0, int _w = 0) : v(_v), w(_w) {}
};

vector<Edge> adj2[SZ];
int color[SZ], cnt = 0;
bool flag = false;

void dfs3(int u)
{
    for(Edge e : adj2[u])
    {
        int v = e.v, w = e.w;
        int ncolor = color[u] ^ w;
        if(color[v] != -1)
        {
            if(color[v] != ncolor)
            {
                flag = true;
                return;
            }
        } else
        {
            color[v] = ncolor;
            dfs3(v);
        }
    }
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    h[1] = 1;
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
    {
        minH[i] = h[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        a[i] = {u,v};
        int p = lca(u,v);
        //cout << u << " " << v << " " << p << '\n';
        minH[u] = min(minH[u], h[p]);
        minH[v] = min(minH[v], h[p]);
        if(p != u && p != v)
        {
            adj2[u].push_back({v, 1});
            adj2[v].push_back({u, 1});
        }
    }
    dfs2(1, 0);
    for(int i = 2; i <= n; i++)
    {
        //cout << minH[i] << ' ';
        if(h[i] - minH[i] >= 2)
        {
            //cout << i << " - " << up[i][0] << '\n';
            adj2[i].push_back({ up[i][0], 0 });
            adj2[ up[i][0] ].push_back({ i, 0 });
        }
    }
    memset(color, -1, sizeof(color))
    for(int i = 2; i <= n; i++)
    {
        if(color[i] == -1)
        {
            cnt++;
            color[i] = 1;
            dfs3(i);
        }
    }
    if(flag)
    {
        cout << 0;
    } else
    {
        ll res = 1;
        for(int i = 1; i <= cnt; i++)
        {
            res = (res * 2) % MOD;
        }
        cout << res;
    }
}
