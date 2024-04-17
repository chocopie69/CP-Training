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
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,s[SZ];
vector<int> adj[SZ];

void dfsSize(int u, int prev)
{
    s[u] = 1;
    for(int v : adj[u])
    {
        if(v == prev) continue;
        dfsSize(v,u);
        s[u] += s[v];
    }
}

void getCentroid(int u, int prev)
{
    if(s[u] <= n/2)
    {
        cout << prev;
        return;
    }
    int maxS = 0,bestV;
    for(int v: adj[u])
    {
        if(v == prev) continue;
        if(s[v] > maxS)
        {
            maxS = s[v];
            bestV = v;
        }
    }
    getCentroid(bestV,u);
}

int main()
{
    init();
    cin >> n;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsSize(1,1);
    getCentroid(1,1);
}
