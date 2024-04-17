#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

struct Matrix
{
    ll adj[SZ][SZ];
} base;

int n,m;
ll k;

Matrix mul(Matrix x, Matrix y)
{
    Matrix res;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            res.adj[i][j] = INFLL;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                res.adj[i][j] = min(res.adj[i][j], x.adj[i][k] + y.adj[k][j]);
            }
        }
    }
    return res;
}

Matrix power(Matrix a, int x)
{
    if(x == 1) return base;
    Matrix cur = power(a, x/2);
    if(x % 2 == 0) return mul(cur,cur);
    return mul(mul(cur,cur),base);
}

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            base.adj[i][j] = INFLL;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        base.adj[u][v] = min(base.adj[u][v],w);
    }
    ll res = INFLL;
    Matrix minhvu = power(base,k);
    for(int i = 1; i <= n; i++)
    {
        res = min(res, minhvu.adj[i][i]);
    }
    cout << (res == INFLL ? -1 : res);
}
