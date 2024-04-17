#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "CIRCLE"

using namespace std;

const int SZ = 2e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Circle
{
    ll x,y,r;
};

ll n,x,y,r, cnt = 0;
bool vis[SZ];
Circle a[SZ];
vector<ll> adj[SZ], res[SZ];

ll dist(ll xi, ll yi, ll xj, ll yj)
{
    return abs(xi-xj) * abs(xi-xj) + abs(yi-yj) * abs(yi-yj);
}

bool check(int i, int j)
{
    ll d = dist(a[i].x, a[i].y, a[j].x, a[j].y);
    return d <= (a[i].r + a[j].r)*(a[i].r + a[j].r);
}

void dfs(int u, int i)
{
    vis[u] = true;
    res[i].push_back(u);
    for(ll v : adj[u])
    {
        if(vis[v]) continue;
        dfs(v, i);
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].r;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(check(i,j))
            {
                adj[i].push_back(j);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(vis[i]) continue;
        cnt++;
        dfs(i, cnt);
        for(ll x : res[cnt])
        {
            cout << x << " ";
        }
        cout << '\n';
    }
}

