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

int n,m, num[SZ], low[SZ], timer = 0, joint[SZ], bridge = 0, cnt = 0;
vector<int> adj[SZ];

void dfs(int u, int prev)
{
    ++timer;
    num[u] = timer;
    low[u] = timer;
    int child = 0;
    //cout << u << " ";
    for(int v : adj[u])
    {
        if(v == prev) continue;
        if(num[v] == 0)
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] == num[v]) bridge++;
            child++;
            if(prev == 0)
            {
                if(child > 1) joint[u] = 1;
            } else if(low[v] >= num[u] && joint[u] == 0)
            {
                //cout << u << " - " << v << '\n';
                joint[u] = 1;
            }
        } else
        {
            low[u] = min(low[u], num[v]);
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
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!num[i]) dfs(i,0);
    }
    for(int i = 1; i <= n; i++)
    {
        cnt += joint[i];
    }
    cout << cnt << " " << bridge;
    //cout << '\n' << num[4] << " " << low[4];
}
