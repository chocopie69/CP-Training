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

string x,y;
int n,m, dp[SZ][SZ];

int main()
{
    init();
    cin >> x >> y;
    n = x.length();
    m = y.length();
    x = " " + x;
    y = " " + y;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(x[i] == y[j]) dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
        }
    }
    cout << n + m - dp[n][m];
}
