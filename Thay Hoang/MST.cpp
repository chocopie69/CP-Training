#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "MST"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,u,v,w, res = 0, d[SZ];
vector<pll> adj[SZ];
bool vis[SZ];

struct cmp
{
    bool operator() (pll x, pll y)
    {
        return x.se > y.se;
    }
};

priority_queue<pll, vector<pll>, cmp> pq;

void prim(ll s)
{
    for(int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    d[s] = 0;
    memset(vis,false,sizeof(vis));
    pq.push({s,0});
    while(!pq.empty())
    {
        u = pq.top().fi;
        ll curDist = pq.top().se;
        pq.pop();
        if(vis[u] || d[u] != curDist) continue;
        vis[u] = true;
        res += d[u];
        for(pll e : adj[u])
        {
            v = e.fi;
            w = e.se;
            if(d[v] > w)
            {
                d[v] = w;
                pq.push({v,d[v]});
            }
        }
    }
}

int main()
{
    init();
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    prim(1);
    cout << res;
}
