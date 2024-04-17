#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "problem"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m, color[SZ], ncolor[SZ], ncolor2[SZ], canChange[SZ];
vector<int> adj[SZ];
bool vis[2][SZ];

int res = 0, cnt, cur;

void dfs(int u, int c, int prev, int k)
{
    if(vis[k][u])
    {
        if( c != ncolor[u] ) cnt = INF;
        return;
    }
    vis[k][u] = true;
    if(canChange[u] == 0 && color[u] != c)
    {
        cnt = INF;
    }
    if(canChange[u] == 1 && c != color[u] && cnt != INF) cnt++;
    ncolor[u] = c;
    for(int v : adj[u])
    {
        if(v != prev) dfs(v, (c == 1 ? 2 : 1), u, k );
    }
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> color[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> canChange[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int u = 1; u <= n; u++)
    {
        cur = INF;
        if(vis[0][u] || vis[1][u]) continue;
        cnt = 0;
        dfs(u, 1, 0, 0);
        cur = min(cur, cnt);
        cnt = 0;
        dfs(u, 2, 0, 1);
        cur = min(cur, cnt);
        if(cur == INF) res = INF;
        else if(res != INF) res += cur;
    }
    cout << (res == INF ? -1 : res);
}
