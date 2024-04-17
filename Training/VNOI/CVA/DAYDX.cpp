#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "DAYDX"

using namespace std;

const int SZ = 5e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, a[SZ], b[SZ], dp[SZ][SZ];

void trace(int i, int j)
{
    if(i == 0 || j == 0) return;
    if(dp[i][j] == dp[i-1][j]) trace(i-1,j);
    else if(dp[i][j] == dp[i][j-1]) trace(i,j-1);
    else if(dp[i][j] == dp[i-1][j-1] + 1)
    {
        trace(i-1,j-1);
        cout << a[i] << " ";
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[n-i+1] = a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if(a[i] == b[j])
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1 );
            }
        }
    }
    if(dp[n][n] < 2)
    {
        cout << 0;
        return 0;
    }
    cout << dp[n][n] << '\n';
    trace(n,n);
}
