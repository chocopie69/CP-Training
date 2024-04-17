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

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,k, c[SZ][SZ], c2[SZ][SZ], res, e;

void reset()
{
    for(int i = 1; i <= n+3; i++)
    {
        for(int j = 1; j <= n+3; j++)
        {
            c2[i][j] = ( (i <= n && j <= n) ? c[i][j] : INFLL);
        }
        c2[i][i] = 0;
    }
    res = 0;
}

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            c[i][j] = INFLL;
        }
        c[i][i] = 0;
    }
    for(int i = 1; i <= m; i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        c[u][v] = min(c[u][v],w);
    }
    for(int x = 1; x <= n; x++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                c[i][j] = min(c[i][j], c[i][x] + c[x][j]);
            }
        }
    }
    while(k--)
    {
        reset();
        cin >> e;
        for(int i = 1; i <= e; i++)
        {
            ll u,v,w;
            cin >> u >> v >> w;
            c2[u][v] = min(c2[u][v],w);
        }
        for(int t = 1; t <= 3; t++)
        {
            for(int i = 1; i <= n+t; i++)
            {
                for(int j = 1; j <= n+t; j++)
                {
                    c2[i][n+t] = min(c2[i][n+t],c2[i][j] + c2[j][n+t]);
                }
            }
            for(int i = 1; i <= n+t; i++)
            {
                for(int j = 1; j <= n+t; j++)
                {
                    c2[n+t][i] = min(c2[n+t][i],c2[n+t][j] + c2[j][i]);
                }
            }
            for(int i = 1; i <= n+t; i++)
            {
                for(int j = 1; j <= n+t; j++)
                {
                    c2[i][j] = min(c2[i][j], c2[i][n+t] + c2[n+t][j]);
                }
            }
        }
        for(int i = 1; i <= n+3; i++)
        {
            for(int j = 1; j <= n+3; j++)
            {
                if(i == j) continue;
                res += c2[i][j];
            }
        }
        cout << res << '\n';
    }
}

