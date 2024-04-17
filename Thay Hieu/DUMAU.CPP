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

const int SZ = 1e4+5;
const ll INF = INT_MAX / 2, MOD = 2021, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m, c[SZ];
vector<int> adj[SZ];
ll dp[SZ], res = 0;

void dfs(int u, int prev, int mask)
{
    dp[u] = ( (mask >> c[u] & 1) ? 0LL : 1LL );
    for(int v : adj[u])
    {
        if(v == prev) continue;
        dfs(v,u,mask);
        dp[u] = (dp[u] * (1LL + dp[v]) ) % MOD;
    }
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
        c[i]--;
    }
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int mask = 0; mask < (1 << m); mask++)
    {
        dfs(1, 0, mask);
        ll sum = 0;
        for(int i = 1; i <= n; i++)
        {
            sum = (sum + dp[i]) % MOD;
        }
        if(__builtin_popcount(mask) % 2 == 1) sum = -sum;
        res = (res + sum + MOD) % MOD;
    }
    cout << res;
}
