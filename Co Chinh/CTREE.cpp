#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "CTREE"

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

int n,m,u,v, start, d[SZ], maxDist = 0, trace[SZ], resA, resB;
vector<int> adj[SZ];
bool vis[SZ];

void dfs(int u)
{
    vis[u] = true;
    if(d[u] > maxDist)
    {
        maxDist = d[u];
        start = u;
        //cout << maxDist << " " << u << '\n';
    }
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            d[v] = d[u] + 1;
            trace[v] = u;
            dfs(v);
        }
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis,false,sizeof(vis));
    memset(d,0,sizeof(d));
    d[1] = 1;
    dfs(1);
    memset(vis,false,sizeof(vis));
    memset(d,0,sizeof(d));
    memset(trace,-1, sizeof(trace));
    d[start] = 1;
    maxDist = 0;
    dfs(start);
    //cout << maxDist << '\n';
    int cnt = 0;
    while(start != -1)
    {
        cnt++;
        if(maxDist % 2 == 0)
        {
            if(cnt == maxDist/2) resA = start;
            if(cnt == maxDist/2 + 1) resB = start;
        } else
        {
            if(cnt == (maxDist+1) / 2) resA = start;
        }
        start = trace[start];
    }
    if(maxDist % 2 == 0)
    {
        cout << 2 << '\n' << min(resA, resB) << " " << max(resA, resB);
    } else
    {
        cout << 1 << '\n' << resA;
    }
}

/*
5
1 2
2 3
3 4
2 5
*/

