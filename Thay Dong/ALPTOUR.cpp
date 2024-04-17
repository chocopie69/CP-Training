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

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n;
ll a[SZ], dp[SZ];
vector<int> adj[SZ], children[SZ];

void dfs(int u, int prev)
{
    dp[u] = a[u];
    ll mx = 0;
    for(int v : adj[u])
    {
        if(v == prev) continue;
        dfs(v,u);
        mx = max(mx, dp[v]);
        children[u].push_back(v);
    }
    dp[u] += mx;
}

ll res = -INFLL;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1; i <= n; i++)
    {
        //cout << dp[i] << " ";
        res = max(res, dp[i]);
        if(children[i].size() < 2)
        {
            continue;
        }
        ll mx1 = -INFLL, mx2 = -INFLL, pos;
        for(int v : children[i])
        {
            if(dp[v] > mx1)
            {
                mx1 = dp[v];
                pos = v;
            }
        }
        for(int v : children[i])
        {
            if(dp[v] > mx2 && v != pos)
            {
                mx2 = dp[v];
            }
        }
        res = max(res, mx1 + mx2 + a[i]);
    }
    cout << res;
}

/*
5
-1 2 3 -2 5
1 2
1 3
1 4
4 5
*/
