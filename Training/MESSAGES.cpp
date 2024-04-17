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

ll n,m, a[SZ][SZ], dp[SZ][SZ], res[SZ];

void recur(int i, int j)
{
    if(i == 0 || j == 0) return;
    bool flag = false;
    for(int k = 1; k <= i; k++)
    {
        if(dp[i][j] == dp[i-k][j-1] + a[k][j])
        {
            res[j] = k;
            flag = true;
            recur(i-k,j-1);
            break;
        }
    }
    if(flag) return;
    res[j] = 0;
    recur(i,j-1);
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            dp[i][j] = INFLL;
            dp[0][j] = 0;
        }
    }
    for(int j = 1; j <= m; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            dp[i][j] = dp[i][j-1];
            for(int k = 1; k <= i; k++)
            {
                dp[i][j] = min(dp[i][j],dp[i-k][j-1] + a[k][j]);
            }
        }
        //cout << dp[n][j] << '\n';
    }
    cout << dp[n][m] << '\n';
    recur(n,m);
    for(int j = 1; j <= m; j++)
    {
        cout << res[j] << '\n';
    }
}

/*
5 4
1 1 1 3
4 4 12 1
4 10 31 5
6 10 20 10
10 5 10 10

5 5
0 0 1 0 1
4 31 12 13 2
4 10 31 2 5
6 6 20 3 12
10 5 10 10 3
*/
