#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n, m, num[SZ], low[SZ], timer = 0, scc[SZ], cnt = 0;
vector<int> adj[SZ], adj2[SZ], topo;
bool deleted[SZ], vis[SZ];
ll a[SZ], sum[SZ], dp[SZ], res = 0;
stack<int> st;

void dfs(int u)
{
    num[u] = low[u] = ++timer;
    st.push(u);
    for(int v : adj[u])
    {
        if(deleted[v]) continue;
        if(!num[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else
        {
            low[u] = min(low[u], num[v]);
        }
    }
    if(low[u] == num[u])
    {
        ++cnt;
        //cout << cnt << ": ";
        while(!st.empty())
        {
            int v = st.top();
            st.pop();
            //cout << v << " ";
            scc[v] = cnt;
            sum[cnt] += a[v];
            deleted[v] = true;
            if(v == u) break;
        }
        //cout << "- " << sum[cnt] << '\n';
    }
}

void dfs2(int u)
{
    vis[u] = true;
    for(int v : adj2[u])
    {
        if(vis[v]) continue;
        dfs2(v);
    }
    topo.push_back(u);
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int u = 1; u <= n; u++)
    {
        if(!num[u]) dfs(u);
    }
    for(int u = 1; u <= n; u++)
    {
        for(int v : adj[u])
        {
            int x = scc[u], y = scc[v];
            if(x != y) adj2[x].push_back(y);
        }
    }
    for(int i = 1; i <= cnt; i++)
    {
        dp[i] = sum[i];
        if(!vis[i]) dfs2(i);
    }
    reverse(all(topo));
    for(int u : topo)
    {
        res = max(res, dp[u]);
        for(int v : adj2[u])
        {
            dp[v] = max(dp[v], dp[u] + sum[v]);
        }
    }
    cout << res;
}

