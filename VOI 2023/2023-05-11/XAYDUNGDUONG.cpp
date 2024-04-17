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

const int SZ = 3e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, dp[SZ], mxPath[SZ];
vector<int> adj[SZ];
pii paths[SZ][3], gay[SZ][2];

void dfs(int u, int prev)
{
    dp[u] = 0;
    paths[u][0] = {n+1, -1};
    paths[u][1] = {n+2, -1};
    paths[u][2] = {n+3, -1};
    int cur = 0;
    for(int v : adj[u])
    {
        if(v == prev) continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v] + 1);
        if(dp[v] > paths[u][0].se)
        {
            paths[u][2] = paths[u][1];
            paths[u][1] = paths[u][0];
            paths[u][0] = {v, dp[v]};
        } else if(dp[v] > paths[u][1].se)
        {
            paths[u][2] = paths[u][1];
            paths[u][1] = {v, dp[v]};
        } else if(dp[v] > paths[u][2].se)
        {
            paths[u][2] = {v, dp[v]};
        }
        cur = max(cur, mxPath[v]);
    }
    mxPath[u] = max(cur, paths[u][0].se + paths[u][1].se + 2);
}

int res = 0;

void solve(int u, int prev, int mx1, int mx2)
{
    res = max(res, mxPath[u] + mx1 + 1);
    if(mx2 > paths[u][0].se)
    {
        paths[u][2] = paths[u][1];
        paths[u][1] = paths[u][0];
        paths[u][0] = {n+4, mx2};
    } else if(mx2 > paths[u][1].se)
    {
        paths[u][2] = paths[u][1];
        paths[u][1] = {n+4, mx2};
    } else if(mx2 > paths[u][2].se)
    {
        paths[u][2] = {n+4, mx2};
    }
    gay[u][0] = {n+1, 0};
    gay[u][1] = {n+2, 0};
    for(int v : adj[u])
    {
        if(v == prev) continue;
        if(mxPath[v] > gay[u][0].se)
        {
            gay[u][1] = gay[u][0];
            gay[u][0] = {v, mxPath[v]};
        } else if(mxPath[v] > gay[u][1].se)
        {
            gay[u][1] = {v, mxPath[v] };
        }
    }
    for(int v : adj[u])
    {
        if(v == prev) continue;
        int pos1 = 0, pos2 = 1, pos3 = 0;
        if(paths[u][0].first == v)
        {
            pos1++;
            pos2++;
        } else if(paths[u][1].first == v)
        {
            pos2++;
        }
        if(gay[u][0].first == v) pos3++;
        solve(v, u, max({ mx1, paths[u][pos1].se + paths[u][pos2].se + 2, gay[u][pos3].se }), paths[u][pos1].se + 1 );
    }
}

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
    dfs(1, 0);
    solve(1, 0, -1, -1);
    cout << res;
}

/*
6
1 2
2 3
2 5
4 5
5 6
*/
