#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "TEAMK"

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

int n,m,k, u, v, s[SZ];
bool vis[SZ], valid[SZ];
vector<int> adj[SZ];
set<int> res;
queue<int> qu;

void bfs(int i)
{
    valid[i] = false;
    res.erase(i);
    qu.push(i);
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        for(int v : adj[u])
        {
            if(!valid[v]) continue;
            s[v]--;
            if(s[v] >= k) continue;
            valid[v] = false;
            res.erase(v);
            qu.push(v);
        }
    }
}

int main()
{
    init();
    cin >> n >> m >> k;
    memset(s,0,sizeof(s));
    memset(valid,true,sizeof(valid));
    while(m--)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        s[u]++;
        s[v]++;
    }
    for(int i = 1; i <= n; i++)
    {
        res.insert(i);
    }
    for(int u = 1; u <= n; u++)
    {
        if(s[u] >= k || !valid[u]) continue;
        bfs(u);
    }
    cout << res.size() << '\n';
    for(int u : res)
    {
        cout << u << " ";
    }
}

