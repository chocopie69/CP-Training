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

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int t, n, m, low[SZ], num[SZ], timer, cnt = 0, scc[SZ], val[SZ];
ll a[SZ], sum[SZ], res, mx;
pll dp[SZ];
vector<int> adj[SZ], adj2[SZ], topo;
stack<int> st;
bool deleted[SZ], vis[SZ];

void reset()
{
    for(int i = 1; i <= n; i++)
    {
        adj[i].clear();
        adj2[i].clear();
        vis[i] = deleted[i] = false;
        num[i] = low[i] = val[i] = sum[i] = 0;
    }
    topo.clear();
    while(!st.empty()) st.pop();
    timer = res = mx = cnt = 0;
}

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
        cnt++;
        //cout << cnt << ": ";
        while(!st.empty())
        {
            int v = st.top();
            st.pop();
            //cout << v << " ";
            scc[v] = cnt;
            val[cnt]++;
            sum[cnt] += a[v];
            deleted[v] = true;
            if(v == u) break;
        }
        cout << '\n';
    }
}

void dfsTopo(int u)
{
    vis[u] = true;
    for(int v : adj2[u])
    {
        if(!vis[v]) dfsTopo(v);
    }
    topo.push_back(u);
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        reset();
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for(int i = 1; i <= m; i++)
        {
            int u,v;
            cin >> u >> v;
            if(u == v) continue;
            adj[u].push_back(v);
        }
        for(int i = 1; i <= n; i++)
        {
            if(!num[i]) dfs(i);
        }
        for(int u = 1; u <= n; u++)
        {
            for(int v : adj[u])
            {
                if(scc[u] != scc[v])
                {
                    adj2[scc[u]].push_back(scc[v]);
                }
            }
        }
        for(int i = 1; i <= cnt; i++)
        {
            dp[i] = {0,0};
            if(!vis[i]) dfsTopo(i);
        }
        reverse(all(topo));
        for(int u : topo)
        {
            dp[u].fi += val[u];
            dp[u].se -= sum[u];
            if(dp[u].fi > res)
            {
                res = dp[u].fi;
                mx = dp[u].se;
            } else if(dp[u].fi == res)
            {
                mx = max(mx, dp[u].se);
            }
            for(int v : adj2[u])
            {
                dp[v] = max(dp[v], dp[u]);
            }
        }
        cout << res << " " << -mx << '\n';
    }
}
