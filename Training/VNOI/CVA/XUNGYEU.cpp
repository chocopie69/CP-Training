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

int n, m, s, t, res = 0, pos[SZ], trace[SZ], mx;
vector<int> adj[SZ], path;
bool vis[SZ];

void dfs(int u)
{
    vis[u] = true;
    if(u == t) return;
    for(int v : adj[u])
    {
        if(vis[v]) continue;
        trace[v] = u;
        dfs(v);
    }
}

void dfs2(int u)
{
    vis[u] = true;
    for(int v : adj[u])
    {
        if(vis[v]) continue;
        if(pos[v] == 0)
        {
            dfs2(v);
        } else
        {
            mx = max(mx, pos[v]);
        }
    }
}

void findPath()
{
    dfs(s);
    int u = t;
    while(true)
    {
        path.push_back(u);
        u = trace[u];
        if(u == 0) break;
    }
    reverse(all(path));
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
    }
    findPath();
    int cnt = 0;
    for(int u : path)
    {
        pos[u] = ++cnt;
        //cout << u << " " << cnt << '\n';
    }
    mx = 0;
    memset(vis, false, sizeof(vis));
    for(int u : path)
    {
        if(u != s && u != t && pos[u] >= mx) res++;
        //cout << u << " " << pos[u] << " " << mx << '\n';
        dfs2(u);
    }
    cout << res;
}
