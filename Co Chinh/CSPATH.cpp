#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "CSPATH"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 123456789, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct cmp
{
    bool operator() (pll x, pll y)
    {
        return x.se > y.se;
    }
};

ll n,m,u,v,w, cnt[SZ], d[SZ];
vector<pll> adj[SZ];
bool vis[SZ];
priority_queue<pll, vector<pll>, cmp> pq;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i = 1; i <= n; i++)
    {
        d[i] = INFLL;
    }
    d[1] = 0;
    for(int i = 1; i <= n; i++)
    {
        cnt[i] = 0;
    }
    cnt[1] = 1;
    pq.push({1,0});
    while(!pq.empty())
    {
        pll cur = pq.top();
        pq.pop();
        u = cur.fi;
        if(vis[u]) continue;
        vis[u] = true;
        for(pll p : adj[u])
        {
            v = p.fi;
            w = p.se;
            if(d[v] == d[u] + w)
            {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
            }
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                cnt[v] = cnt[u];
                pq.push({v,d[v]});
            }
        }
    }
    cout << d[n] << '\n' << cnt[n];
}

/*
5 8
1 2 1
1 3 2
2 3 1
2 4 1
2 5 3
3 4 9
3 5 2
4 5 2
*/

