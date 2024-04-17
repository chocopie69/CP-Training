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
const ll INF = INT_MAX / 2, MOD = 998244353, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

string x,y;
int n, m;
ll dp[SZ][SZ][2], cntx[SZ], cnty[SZ], res = 0;

int main()
{
    init();
    cin >> x >> y;
    n = x.length();
    m = y.length();
    x = " " + x;
    y = " " + y;
    for (int i = 1; i <= n; i++){
        if (x[i] != x[i-1]) cntx[i] = cntx[i-1] + 1;
        else cntx[i] = 1;
    }
    for (int j = 1; j <= m; j++){
        if (y[j] != y[j-1]) cnty[j] = cnty[j-1] + 1;
        else cnty[j] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(x[i] != y[j])
            {
                dp[i][j][0] += cnty[j];
                dp[i][j][1] += cntx[i];
                dp[i][j][0] += dp[i-1][j][1];
                dp[i][j][1] += dp[i][j-1][0];
            }
            if(x[i] != x[i-1]) dp[i][j][0] += dp[i-1][j][0];
            if(y[j] != y[j-1]) dp[i][j][1] += dp[i][j-1][1];
            dp[i][j][0] %= MOD;
            dp[i][j][1] %= MOD;
            res = (res + dp[i][j][0] + dp[i][j][1]) % MOD;
        }
    }
    cout << res;
}
