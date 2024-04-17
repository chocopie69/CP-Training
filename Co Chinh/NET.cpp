#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NET"

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

ll n,m,k,l,f[SZ][3], u, v, a[SZ], b[SZ], trace[SZ], res = 0;
vector<ll> adj[SZ];
vector<pll> edges;
bool vis[SZ];

void dfs(ll u, ll i)
{
    vis[u] = true;
    if(i == 1)
    {
        f[u][i] = a[u];
    } else
    {
        f[u][i] = b[u];
    }
    for(ll v : adj[u])
    {
        if(vis[v]) continue;
        dfs(v, i);
        f[u][i] += f[v][i];
        trace[v] = u;
    }
}

void preCalc()
{
    memset(vis,false,sizeof(vis));
    memset(trace,-1,sizeof(trace));
    dfs(1,1);
    memset(vis,false,sizeof(vis));
    dfs(1,2);
}

int main()
{
    init();
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin >> n >> m >> k >> l;
    while(k--)
    {
        ll x;
        cin >> x;
        a[x] = 1;
    }
    while(l--)
    {
        ll x;
        cin >> x;
        b[x] = 1;
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        edges.push_back({u,v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    preCalc();
    for(pll e : edges)
    {
        u = e.fi;
        v = e.se;
        if(trace[u] == v) swap(u,v);
        if(f[v][1] == k || f[v][1] == 0 || f[v][2] == l || f[v][2] == 0)
        {
            res++;
            cout << "Choose " << u << " " << v << '\n';
        }
        cout << f[v][1] << " " << f[v][2] << " " << v << '\n';
    }
    cout << res;
}

