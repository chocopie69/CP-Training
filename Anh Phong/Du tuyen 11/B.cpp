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

int n,m,q;
ll a[SZ];
vector<int> adj[SZ];
bool vis[SZ];
vector<ll> dp[SZ][3];

void preDfs(int u)
{
    vis[u] = true;
    for(int v : adj[u])
    {
        if(vis[v]) continue;
        preDfs(v);
    }
}

void dfs(int u, int pre)
{
    dp[u][0] = {0,INFLL};
    dp[u][1] = {a[u], INFLL};
    dp[u][2] = {INFLL, INFLL};
    for(int v : adj[u])
    {
        if(v == pre) continue;
        dfs(v, u);
        ll s = dp[u][0].size() + dp[v][0].size() - 1;
        vector<ll> t0(s, INFLL), t1(s, INFLL), t2(s, INFLL);
        for(int i = 0; i < dp[u][0].size(); i++)
        {
            for(int j = 0; j < dp[v][0].size(); j++)
            {
                t0[i+j] = min(t0[i+j], dp[u][0][i] + min({ dp[v][0][j], dp[v][1][j], dp[v][2][j] }));
                t1[i+j] = min(t1[i+j], dp[u][1][i] + dp[v][0][j]);
                t2[i+j] = min(t2[i+j], dp[u][2][i] + min(dp[v][2][j], dp[v][0][j]));
                if(i + j + 1 < t2.size()) t2[i + j + 1] = min({ t2[i+j+1], dp[u][2][i] + dp[v][1][j], dp[u][1][i] + dp[v][2][j] });
                if(i + j + 2 < t2.size()) t2[i+j+2] = min(t2[i+j+2], dp[u][1][i] + dp[v][1][j]);
            }
        }
        dp[u][0] = t0;
        dp[u][1] = t1;
        dp[u][2] = t2;
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
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    a[0] = INFLL;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i]) continue;
        preDfs(i);
        adj[0].pb(i);
    }
    dfs(0,0);
    for (int i = n - 1; i >= 0; --i){
        dp[0][0][i] = min(dp[0][0][i], dp[0][0][i + 1]);
    }
    cin >> q;
    while(q--)
    {
        ll s;
        cin >> s;
        int pos = upb(dp[0][0].begin()+2, dp[0][0].end(),s) - dp[0][0].begin() - 1;
        if(pos == 1) pos--;
        cout << pos << '\n';
    }
}

