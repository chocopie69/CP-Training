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

int n,m,s,t, d[SZ], q[SZ], idx = 0, trace[SZ], par[SZ][20], mn[SZ][20];
vector<int> adj[SZ];
queue<int> qu;
bool vis[SZ];

bool better(int u, int v)
{
    int umin = n+1, vmin = n+1;
    for(int i = 18; i >= 0; i--)
    {
        if(par[u][i] != par[v][i])
        {
            umin = min(umin, mn[u][i]);
            vmin = min(vmin, mn[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    umin = min(umin, u); vmin = min(vmin, v); /// IMPORTANT
    return umin < vmin;
}

int main()
{
    init();
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    swap(s,t);
    qu.push(s);
    vis[s] = true;
    q[++idx] = s;
    d[s] = 0;
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for(int v : adj[u])
        {
            if(!vis[v])
            {
                qu.push(v);
                d[v] = d[u] + 1;
                vis[v] = true;
                q[++idx] = v;
            }
        }
    }
    if(!vis[t])
    {
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        int u = q[i];
        for(int v : adj[u])
        {
            if(d[v] == d[u] - 1)
            {
                if(trace[u] == 0 || better(v, trace[u]))
                {
                    trace[u] = v;
                }
            }
        }
        mn[u][0] = u;
        par[u][0] = trace[u];
        for(int i = 1; i <= 18; i++)
        {
            int x = par[u][i-1];
            par[u][i] = par[x][i-1];
            mn[u][i] = min(mn[u][i-1], mn[x][i-1]);
        }
    }
    int u = t;
    while(u != 0)
    {
        cout << u << " ";
        u = trace[u];
    }
}
