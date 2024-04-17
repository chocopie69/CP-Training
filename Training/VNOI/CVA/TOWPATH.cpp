#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n, dp[SZ], res = 0;
vector<int> adj[SZ];

void dfs(int u, int pre)
{
    for(int v : adj[u])
    {
        if(v == pre) continue;
        dfs(v,u);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}

void solve(int u, int pre, int mx)
{
    pii mx1 = {0,-1}, mx2 = {0,-1};
    for(int v : adj[u])
    {
        if(v == pre) continue;
        if(dp[v] > mx1.se)
        {
            mx2 = mx1;
            mx1 = {v, dp[v]};
        } else if(dp[v] > mx2.se)
        {
            mx2 = {v, dp[v]};
        }
    }
    res = max(res, dp[u] * mx);
    cout << u << " " << dp[u] << " " << mx << '\n';
    for(int v : adj[u])
    {
        if(v == pre) continue;
        if(v == mx1.fi)
        {
            solve(v, u, max(mx2.se+1, mx+1));
        } else
        {
            solve(v, u, max(mx1.se+1, mx+1));
        }
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
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    //for(int i = 1; i <= n; i++) cout << dp[i] << " ";
    solve(1,0,-1);
    cout << res;
}

