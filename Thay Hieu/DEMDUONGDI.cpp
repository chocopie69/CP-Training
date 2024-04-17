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

const int SZ = 50+5;
const ll INF = INT_MAX / 2, MOD = 2017, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m;
ll k;

struct Matrix
{
    ll adj[SZ][SZ];

    Matrix()
    {
        memset(adj, 0, sizeof(adj));
    }
};

Matrix mul(Matrix a, Matrix b)
{
    Matrix res;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                res.adj[i][j] = (res.adj[i][j] + a.adj[i][k] * b.adj[k][j]) % MOD;
            }
        }
    }
    return res;
}

Matrix base;

Matrix power(Matrix a, int x)
{
    if(x == 1) return a;
    Matrix cur = power(a, x/2);
    if(x % 2 == 0) return mul(cur, cur);
    return mul(mul(cur,cur),a);
}

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        base.adj[u][v]++;
    }
    Matrix res = power(base, k);
    cout << res.adj[1][n];
}
