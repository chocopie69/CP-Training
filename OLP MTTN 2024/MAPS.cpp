#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m;
vector<pair<int,ll>> adj[SZ];
ll d[SZ];
vector<int> vec[SZ];

struct cmp
{
    bool operator() (pll x, pll y)
    {
        return x.second > y.second;
    }
};

priority_queue<pll, vector<pll>, cmp> pq;

void dijkstra(int s)
{
    for(int i = 1; i <= n; i++)
    {
        d[i] = INFLL;
    }
    d[s] = 0;
    pq.push({s,0});
    while(!pq.empty())
    {
        pair<int,ll> cur = pq.top();
        pq.pop();
        int u = cur.fi;
        if(cur.se > d[u]) continue;
        for(pair<int,ll> p : adj[u])
        {
            int v = p.first;
            ll w = p.second;
            if(d[v] > d[u] + w)
            {
                vec[v].clear();
                vec[v].pb(u);
                d[v] = d[u] + w;
                pq.push({v, d[v]});
            } else if(d[v] == d[u] + w)
            {
                vec[v].pb(u);
            }
        }
    }
}


int k, path[SZ], mn = 0, mx = 0;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    cin >> k;
    for(int i = 1; i <= k; i++)
    {
        cin >> path[i];
    }
    dijkstra(path[k]);
    for(int i = 1; i < k; i++)
    {
        int u = path[i], nx = path[i+1];
        bool flag = false;
        for(int v : vec[u])
        {
            if(v == nx)
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            mx++;
            mn++;
        } else if(vec[u].size() > 1) mx++;
    }
    cout << mn << " " << mx;
}
