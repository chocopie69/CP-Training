#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BAI5"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, p[SZ];
vector<ll> adj[SZ];

ll dfs(int u)
{
    ll res = 1;
    for(int v : adj[u])
    {
        res = ((res % MOD) * (dfs(v) % MOD)) % MOD;
    }
    return (res + 1) % MOD;
}

int main()
{
    init();
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    cout << (dfs(1) - 1 + MOD) % MOD;
}