#include <bits/stdc++.h>
#define ll long long
#define int long long
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
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,s[SZ],k,h[SZ], cnt[SZ], res = 0, cur;
vector<int> adj[SZ], vertices;
bool deleted[SZ];

void dfsSize(int u, int prev)
{
    s[u] = 1;
    for(int v : adj[u])
    {
        if(v == prev || deleted[v]) continue;
        dfsSize(v,u);
        s[u] += s[v];
    }
}

int getCentroid(int u, int prev, int treeSize)
{
    if(treeSize == 1)
    {
        return u;
    }
    if(s[u] <= treeSize/2)
    {
        return prev;
    }
    int maxS = 0,bestV;
    for(int v: adj[u])
    {
        if(v == prev || deleted[v]) continue;
        if(s[v] > maxS)
        {
            maxS = s[v];
            bestV = v;
        }
    }
    return getCentroid(bestV,u,treeSize);
}

void updateRes(int u, int prev)
{
    if(h[u] > k) return;
    vertices.push_back(u);
    res += cnt[k-h[u]];
    for(int v : adj[u])
    {
        if(v == prev || deleted[v]) continue;
        h[v] = h[u] + 1;
        updateRes(v,u);
    }
}

void solve(int u)
{
    dfsSize(u,0);
    int treeSize = s[u], root = getCentroid(u,0,treeSize);
    deleted[root] = true;
    for(int i = 1; i <= k; i++)
    {
        cnt[i] = 0;
    }
    cnt[0] = 1;
    for(int v : adj[root])
    {
        if(deleted[v]) continue;
        h[v] = 1;
        updateRes(v,root);
        for(int x : vertices)
        {
            cnt[h[x]]++;
        }
        vertices.clear();
    }
    for(int v : adj[root])
    {
        if(!deleted[v])
        {
            solve(v);
        }
    }
}

signed main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i < n; i++)
    {
        int u ,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(deleted,false,sizeof(deleted));
    solve(1);
    cout << res;
}

/*
7 2
1 2
2 3
3 4
3 5
4 6
6 7
*/
