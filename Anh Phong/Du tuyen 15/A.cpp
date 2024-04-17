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

const int SZ = 3e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int t,n, num[SZ], depth[SZ], depth2[SZ], h[SZ], rmq[SZ][19], timer = 0, res = 0;
vector<int> adj[SZ], adj2[SZ], tour;
set<int> s[SZ];

void preDfs(int u, int p)
{
    num[u] = ++timer;
    tour.pb(num[u]);
    depth[num[u]] = depth[num[p]] + 1;
    h[num[u]] = tour.size() - 1;
    for(int v : adj2[u])
    {
        if(v == p) continue;
        preDfs(v, u);
        tour.pb(num[u]);
    }
}

void reset()
{
    for (int i = 1; i < tour.size(); i++)
    {
        for (int j = 0; j <= __lg(tour.size()) + 1; j++) rmq[i][j] = 0;
    }
    memset(num, 0, sizeof(num));
    memset(depth, 0, sizeof(depth));
    memset(depth2, 0, sizeof(depth2));
    memset(h, 0, sizeof(h));
    res = timer = 0;
    tour.clear();
    for(int i = 1; i <= n; i++)
    {
        s[i].clear();
        adj[i].clear();
        adj2[i].clear();
    }
}

int lca(int u, int v)
{
    if(u == v) return u;
    if(h[u] > h[v]) swap(u,v);
    int k = __lg(h[v] - h[u] + 1);
    u = rmq[h[u]][k];
    v = rmq[h[v] - (1 << k) + 1 ][k];
    return depth[u] < depth[v] ? u : v;
}

void update(int v, int u)
{
    s[u].insert(v);
    if(s[u].size() == 1) return;
    auto k = s[u].find(v);
    if(k == s[u].begin())
    {
        k++;
        res = max(res, depth2[u] + depth[lca(*k, v)] );
        return;
    }
    k++;
    if(k == s[u].end())
    {
        k--; k--;
        res = max(res, depth2[u] + depth[lca(*k, v)] );
        return;
    }
    res = max(res, depth2[u] + depth[lca(*k, v)] );
    k--; k--;
    res = max(res, depth2[u] + depth[lca(*k, v)] );
}

void dfs(int u, int p)
{
    depth2[u] = depth2[p] + 1;
    s[u].insert(num[u]);
    for(int v : adj[u])
    {
        if(v == p) continue;
        dfs(v, u);
        if(s[u].size() < s[v].size()) swap(s[u], s[v]);
        for(int j : s[v])
        {
            update(j, u);
        }
    }
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i < n; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(int i = 1; i < n; i++)
        {
            int u,v;
            cin >> u >> v;
            adj2[u].pb(v);
            adj2[v].pb(u);
        }
        tour.pb(0);
        preDfs(1,1);
        for(int i = 1; i < tour.size(); i++)
        {
            rmq[i][0] = tour[i];
        }
        for(int j = 1; j <= __lg(tour.size()) + 1 ; j++)
        {
            for(int i = 1; i < tour.size(); i++)
            {
                int k = i + (1 << (j-1));
                if(k > tour.size()) rmq[i][j] = rmq[i][j-1];
                else rmq[i][j] = ( depth[rmq[i][j-1]] < depth[rmq[k][j-1]] ? rmq[i][j-1] : rmq[k][j-1] );
            }
        }
        dfs(1, 1);
        cout << res << '\n';
        reset();
    }
}

