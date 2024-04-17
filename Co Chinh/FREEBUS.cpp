#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "FREEBUS"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,k,s,t, d[SZ][10], res = INFLL;
bool vis[SZ];
vector<pll> adj[SZ];

struct Node
{
    ll u, d, cnt;

    Node(ll _u, ll _d, ll _cnt)
    {
        u = _u;
        d = _d;
        cnt = _cnt;
    }
};

struct cmp
{
    bool operator() (Node x, Node y)
    {
        return x.d > y.d;
    }
};

priority_queue<Node, vector<Node>, cmp> pq;

int main()
{
    init();
    cin >> n >> m;
    k = 1;
    s = 1;
    t = n;
    for(int i = 1; i <= m; i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= k; j++)
        {
            d[i][j] = INFLL;
        }
    }
    d[s][0] = 0;
    pq.push({s,0,0});
    memset(vis,false,sizeof(vis));
    while(!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();
        ll u = cur.u, cnt = cur.cnt;
        if(cur.d > d[u][cnt]) continue;
        for(pll p : adj[u])
        {
            ll v = p.first, w = p.second;
            if(d[v][cnt] > d[u][cnt] + w)
            {
                d[v][cnt] = d[u][cnt] + w;
                pq.push({v, d[v][cnt],cnt});
            }
            if(cnt < k && d[v][cnt+1] > d[u][cnt])
            {
                d[v][cnt+1] = d[u][cnt];
                pq.push({v,d[v][cnt+1],cnt+1});
            }
        }
    }
    for(int i = 0; i <= k; i++)
    {
        res = min(res,d[t][i]);
    }
    cout << res;
}



