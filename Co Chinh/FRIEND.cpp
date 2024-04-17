#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "FRIEND"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

ll n,m,u,v,w, sA, tA, sB, tB, d[5][SZ], trace[5][SZ], res = INFLL, tg;
vector<pll> adj[SZ];
vector<ll> a,b;
bool vis[SZ], flag = false;

struct cmp
{
    bool operator() (pll x, pll y)
    {
        return x.se > y.se;
    }
};

priority_queue<pll, vector<pll>, cmp> pq;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void dijkstra(ll s, ll x)
{
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; i++)
    {
        d[x][i] = INFLL;
    }
    d[x][s] = 0;
    pq.push({s,0});
    while(!pq.empty())
    {
        u = pq.top().fi;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(pll p : adj[u])
        {
            v = p.fi;
            w = p.se;
            if(d[x][v] > d[x][u] + w)
            {
                d[x][v] = d[x][u] + w;
                pq.push({v,d[x][v]});
                trace[x][v] = u;
            }
        }
    }
}

void recur(ll t, ll x)
{
    if(t == -1) return;
    recur(trace[x][t], x);
    cout << t << " ";
}

int main()
{
    init();
    cin >> n >> m >> sA >> tA >> sB >> tB;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    memset(trace,-1,sizeof(trace));
    dijkstra(sA,1);
    dijkstra(tA,2);
    dijkstra(sB,3);
    dijkstra(tB,4);
    for(int i = 1; i <= n; i++)
    {
        if(d[1][i] + d[2][i] == d[1][tA] && d[3][i] + d[4][i] == d[3][tB] && d[1][i] == d[3][i])
        {
            flag = true;
            if(d[1][i] < res)
            {
                res = d[1][i];
                tg = i;
            }
        }
    }
    cout << (flag == true ? "YES" : "NO");
    cout << '\n';
    if(!flag) return 0;
    cout << d[1][tA] << '\n';
    recur(tA,1);
    cout << '\n' << d[3][tB] << '\n';
    recur(tB,3);
    cout << '\n' << tg << '\n' << d[1][tg];
}

