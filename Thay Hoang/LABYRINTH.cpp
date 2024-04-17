#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "LABYRINTH"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,k;
vector<int> adj[LIMIT];
bool unlocked[LIMIT];

struct DSU
{
    int par[LIMIT], sz[LIMIT];

    void init(int n)
    {
        for(int i = 0; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int get(int u)
    {
        return par[u] == u ? u : par[u] = get(par[u]);
    }

    void join(int u, int v)
    {
        u = get(u), v = get(v);
        if(sz[v] < sz[u]) swap(u,v);
        sz[v] += sz[u];
        par[v] = u;
    }
};

struct Message
{
    char type;
    int u,s,t;
};

DSU dsu;

int main()
{
    init();
    cin >> n >> m >> k;
    dsu.init(n);
    memset(unlocked,false,sizeof(unlocked));
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Message msg;
    while(k--)
    {
        cin >> msg.type;
        if(msg.type == 'X')
        {
            cin >> msg.u;
            unlocked[msg.u] = true;
            for(int v : adj[msg.u])
            {
                if(!unlocked[v]) continue;
                dsu.join(msg.u,v);
            }
        }
        else
        {
            cin >> msg.s >> msg.t;
            cout << (dsu.get(msg.s) == dsu.get(msg.t) ? 'Y' : 'N');
        }
    }
}

