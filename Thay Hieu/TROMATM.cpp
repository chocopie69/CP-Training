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

int n,m, num[SZ], low[SZ], timer = 0, cnt = 0, s, p, startScc, inScc[SZ];
vector<int> adj[SZ], scc[SZ], adj2[SZ];
ll a[SZ], sum[SZ];
stack<int> st;
bool deleted[SZ], hasGame[SZ], sccHasGame[SZ];

void dfs(int u)
{
    ++timer;
    num[u] = timer;
    low[u] = timer;
    st.push(u);
    for(int v : adj[u])
    {
        if(deleted[v]) continue;
        if(num[v] == 0)
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
        while(!st.empty())
        {
            int v = st.top();
            st.pop();
            scc[cnt].push_back(v);
            deleted[v] = true;
            if(v == s) startScc = cnt;
            if(hasGame[v]) sccHasGame[cnt] = true;
            sum[cnt] += a[v];
            inScc[v] = cnt;
            if(v == u) break;
        }
    }
}

vector<int> topo;
bool vis[SZ];

void dfsTopo(int u)
{
    vis[u] = true;
    for(int v : adj2[u])
    {
        if(!vis[v]) dfsTopo(v);
    }
    topo.push_back(u);
}

ll dp[SZ];

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> s >> p;
    for(int i = 1; i <= p; i++)
    {
        int x;
        cin >> x;
        hasGame[x] = true;
    }
    for(int i = 1; i <= n; i++)
    {
        if(num[i] == 0) dfs(i);
    }
//    for(int i = 1; i <= cnt; i++)
//    {
//        bool flag = false;
//        cout << i << ": ";
//        for(int u : scc[i])
//        {
//            cout << u << " ";
//        }
//        cout << '\n';
//    }
    for(int i = 1; i <= cnt; i++)
    {
        for(int u : scc[i])
        {
            for(int v : adj[u])
            {
                if(inScc[v] != i)
                {
                    adj2[i].push_back(inScc[v]);
                    //cout << i << " - " << inScc[v] << '\n';
                }
            }
        }
    }
    for(int i = 1; i <= cnt; i++)
    {
        if(!vis[i]) dfsTopo(i);
        if(i == startScc) dp[i] = sum[i];
    }
    reverse(all(topo));
    ll mx = 0;
    for(int u : topo)
    {
        //cout << u << " ";
        if(dp[u] == 0) continue;
        if(sccHasGame[u])
        {
            mx = max(mx, dp[u]);
        }
        for(int v : adj2[u])
        {
            dp[v] = max(dp[v], dp[u] + sum[v]);
        }
    }
    cout << mx;
}
