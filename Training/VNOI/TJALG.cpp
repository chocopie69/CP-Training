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

int n,m, num[SZ], low[SZ], timer = 0, res = 0;
vector<int> adj[SZ];
stack<int> st;
bool deleted[SZ];

void dfs(int u)
{
    ++timer;
    num[u] = timer;
    low[u] = timer;
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
        res++;
        while(!st.empty())
        {
            int v = st.top();
            st.pop();
            deleted[v] = true;
            if(v == u) break;
        }
    }
}

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
        if(!num[i]) dfs(i);
    }
    cout << res;
}
