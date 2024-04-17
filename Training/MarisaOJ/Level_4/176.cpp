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

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m,k;
vector<pll> adj[SZ];
ll d[SZ][6];

struct Node
{
    int u,cnt;
    ll dist;

    Node(int _u = 0, int _cnt = 0, ll _dist = 0) : u(_u), cnt(_cnt), dist(_dist) {}

    bool operator < (const Node& other) const
    {
        return dist > other.dist;
    }

};

priority_queue<Node> pq;

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0 ; j <= 5; j++)
        {
            d[i][j] = INFLL;
        }
    }
    d[1][0] = 0;
    pq.push({1,0,0});
    while(!pq.empty())
    {
        Node cur = pq.top();
        pq.pop();
        int u = cur.u, cnt = cur.cnt;
        ll dist = cur.dist;
        if(dist > d[u][cnt]) continue;
        for(pll e : adj[u])
        {
            int v = e.fi;
            ll w = e.se;
            if(d[v][cnt] > d[u][cnt] + w)
            {
                d[v][cnt] = d[u][cnt] + w;
                pq.push({v, cnt, d[v][cnt] });
            }
            if(cnt < k && d[v][cnt+1] > d[u][cnt] )
            {
                d[v][cnt+1] = d[u][cnt];
                pq.push({v, cnt+1, d[v][cnt+1] });
            }
        }
    }
    ll res = INFLL;
    for(int j = 0; j <= k; j++)
    {
        res = min(res, d[n][j]);
    }
    cout << (res == INFLL ? -1 : res);
}

