#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "ETOUR"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t,n,m,u,v, deg[SZ];
bool vis[SZ];
vector<int> adj[SZ];

void reset()
{
    for(int i = 1; i <= n; i++)
    {
        vis[i] = false;
        deg[i] = 0;
        adj[i].clear();
    }
}

void dfs(int u)
{
    vis[u] = true;
    for(int v : adj[u])
    {
        if(!vis[v]) dfs(v);
    }
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        reset();
        for(int i = 1; i <= m; i++)
        {
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool flag = false;
        for(int i = 1; i <= n; i++)
        {
            if(deg[i] % 2 != 0)
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            cout << "NO" << '\n';
            continue;
        }
        flag = false;
        bool started = false;
        for(int i = 1; i <= n; i++)
        {
            if(deg[i] == 0) continue;
            if(!started)
            {
                started = true;
                dfs(i);
            } else if(!vis[i])
            {
                cout << "NO" << '\n';
                flag = true;
                break;
            }
        }
        if(!flag) cout << "YES" << '\n';
    }
}

/*
1
10 12
1 2
2 5
1 5
1 8
1 4
8 4
4 3
10 9
10 6
6 9
3 7
4 7
*/
