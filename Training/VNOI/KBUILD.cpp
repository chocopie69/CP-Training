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
set<pii> s;

void dfs(int u, int prev)
{
    timer++;
    num[u] = timer;
    low[u] = timer;
    int cnt = 0;
    for(int v : adj[u])
    {
        if(v == prev) cnt++;
        if(v != prev || cnt > 1)
        {
            if(!num[v])
            {
                dfs(v,u);
                low[u] = min(low[u],low[v]);
                if(low[v] == num[v])
                {
                    res++;
                }
            } else
            {
                low[u] = min(low[u], num[v]);
            }
        }
    }
}

int cnt = 0;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,1);
    cout << res;
}
