#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "CIRCUIT"

using namespace std;

const int SZ = (int) 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,trace[SZ], color[SZ], start = 0;
vector<int> adj[SZ], res;
map<pii,int> mp;

bool dfs(int u)
{
    color[u] = 2;
    for(int v : adj[u])
    {
        trace[v] = u;
        if(color[v] == 1)
        {
            if(dfs(v)) return true;
        }
        else if(color[v] == 2)
        {
            start = v;
            return true;
        }
    }
    color[u] = 3;
    return false;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        if(u == v)
        {
            cout << "YES" << '\n' << m;
            return 0;
        }
        adj[u].push_back(v);
        mp[{u,v}] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        color[i] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        if(dfs(i))
        {
            cout << "YES" << '\n';
            int u = start;
            while(true)
            {
                res.push_back(mp[{trace[u],u}]);
                u = trace[u];
                if(u == start) break;
            }
            for(int i = res.size()-1; i >= 0; i--)
            {
                cout << res[i] << " ";
            }
            return 0;
        }
    }
    cout << "NO";
}

