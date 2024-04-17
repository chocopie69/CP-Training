#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "KEFA"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,u,v, d[SZ], a[SZ], res;
vector<int> adj[SZ];
bool vis[SZ];
queue<int> qu;

void bfs()
{
    qu.push(1);
    d[1] = a[1];
    vis[1] = true;
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        if(d[u] > m) continue;
        bool flag = false;
        for(int v : adj[u])
        {
            if(!vis[v])
            {
                flag = true;
                vis[v] = true;
                qu.push(v);
                d[v] = (a[v] == 1 ? d[u]+1 : 0);
            }
        }
        if(!flag) res++;
    }
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n-1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(d,-1, sizeof(d));
    memset(vis, false, sizeof(vis));
    bfs();
    cout << res;
}

