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

int n,m, root, pos[SZ], cur = 0;
vector<int> child[SZ], par[SZ];
bool vis[SZ];

void dfs(int u)
{
    vis[u] = true;
    for(int v : child[u])
    {
        if(vis[v]) continue;
        dfs(v);
    }
    pos[u] = ++cur;
    //cout << u << " - " << cur << '\n';
}

bool cmp(int x, int y)
{
    return pos[x] < pos[y];
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n-1 + m; i++)
    {
        int u,v;
        cin >> u >> v;
        child[u].push_back(v);
        par[v].push_back(u);
    }
    for(int u = 1; u <= n; u++)
    {
        if(par[u].empty())
        {
            root = u;
            par[u].push_back(0);
        }
    }
    dfs(root);
    for(int u = 1; u <= n; u++)
    {
        sort(all(par[u]), cmp);
        cout << par[u][0] << '\n';
    }
}
