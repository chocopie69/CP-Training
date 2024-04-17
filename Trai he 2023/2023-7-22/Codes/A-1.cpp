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

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, h[SZ], deg[SZ];
vector<int> adj[SZ];
set<int> s;

void trace(int u, int prev, int top)
{
    if(s.find(u) != s.end()) s.erase(u);
    for(int v : adj[u])
    {
        if(v == prev) continue;
        if(v == top)
        {
            deg[top]--;
        } else
        {
            trace(v,u,top);
        }
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] <= 1) s.insert(i);
    }
    int lca;
    while(s.size() > 1)
    {
        int u = *s.begin();
        s.erase(u);
        int v = *s.begin();
        s.erase(v);
        cout << "? " << u << " " << v << '\n';
        cout.flush();
        cin >> lca;
        if(lca == u || lca == v)
        {
            cout << "! " << lca << '\n';
            cout.flush();
            return 0;
        }
        trace(u,-1,lca);
        trace(v,-1,lca);
        if(deg[lca] <= 1) s.insert(lca);
    }
    cout << "! " << *s.begin() << '\n';
    cout.flush();
}
