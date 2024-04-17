#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NUCLEAR"

using namespace std;

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m, d[SZ], res = 0, k, q;
vector<pll> adj[SZ];

struct cmp
{
    bool operator() (pll x, pll y)
    {
        return x.second > y.second;
    }
};

priority_queue<pll, vector<pll>, cmp> pq;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin >> k;
    for(int i = 1; i <= k; i++)
    {
        ll x;
        cin >> x;
        adj[0].push_back({x,0});
    }
    for(int i = 1; i <= n; i++)
    {
        d[i] = INFLL;
    }
    d[0] = 0;
    pq.push({0,0});
    while(!pq.empty())
    {
        pll cur = pq.top();
        pq.pop();
        ll u = cur.fi;
        if(cur.se > d[u]) continue;
        for(pll p : adj[u])
        {
            ll v = p.first, w = p.second;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({v, d[v]});
            }
        }
    }
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        ll x;
        cin >> x;
        cout << (d[x] == INFLL ? -1 : d[x]) << " ";
    }
}


