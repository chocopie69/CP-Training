#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "TREE"

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

ll f[SZ], n, u, v, res = 0;
vector<ll> adj[SZ];
bool vis[SZ];

void dfs(ll u)
{
    f[u] = 1;
    vis[u] = true;
    for(ll v : adj[u])
    {
        if(vis[v]) continue;
        dfs(v);
        f[u] += f[v];
        res += f[v] * (n - f[v]);
        cout << u << " " << v << " " << f[v] * (n - f[v]) << '\n';
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    dfs(1);
    cout << res;
}
