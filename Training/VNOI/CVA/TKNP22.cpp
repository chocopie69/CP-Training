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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,s,t;
ll a[SZ];
vector<int> adj[SZ];

bool vis[SZ];

void dfs(int u, int x)
{
    vis[u] = true;
    for(int v : adj[u])
    {
        if(vis[v] || abs(a[v] - a[u]) > x) continue;
        dfs(v,x);
    }
}

bool check(int x)
{
    memset(vis, false, sizeof(vis));
    dfs(s,x);
    return vis[t];
}

int main()
{
    init();
    cin >> n >> s >> t;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int u,v;
    while(cin >> u)
    {
        cin >> v;
        if(u == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int lo = 0, hi = 20002, mid;
    bool flag = false;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(check(mid))
        {
            hi = mid-1;
            flag = true;
        } else
        {
            lo = mid+1;
        }
    }
    cout << (flag ? lo : -1);
}
