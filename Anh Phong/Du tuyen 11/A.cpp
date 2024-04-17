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

const int SZ = 5e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n;
ll money, a[SZ], b[SZ];
vector<int> adj[SZ];
vector<ll> dp[SZ][2];

vector<ll> combine(vector<ll> x, vector<ll> y)
{
    vector<ll> combined(x.size() + y.size() - 1, INFLL);
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < y.size(); j++) {
			combined[i + j] = min(combined[i + j], x[i] + y[j]);
		}
	}
	return combined;
}

void dfs(int u)
{
    dp[u][0] = {0, a[u]};
    dp[u][1] = {INFLL, b[u]};
    for(int v : adj[u])
    {
        dfs(v);
        dp[u][0] = combine(dp[u][0], dp[v][0]);
        dp[u][1] = combine(dp[u][1], dp[v][1]);
    }
    for(int i = 0; i < dp[u][1].size(); i++)
    {
        dp[u][1][i] = min(dp[u][1][i], dp[u][0][i]);
    }
}

int main()
{
    init();
    cin >> n >> money;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        b[i] = a[i] - b[i];
        if(i >= 2)
        {
            int u;
            cin >> u;
            adj[u].pb(i);
        }
    }
    dfs(1);
    for(int i = n; i >= 0; i--)
    {
        if(dp[1][1][i] <= money)
        {
            cout << i;
            return 0;
        }
    }
}

