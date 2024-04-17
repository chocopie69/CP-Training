#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 3000+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
double a[SZ], dp[SZ][SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n/2 + 1; j++)
        {
            dp[i][j] = dp[i-1][j-1] * a[i] + dp[i-1][j]*(1-a[i]);
        }
    }
    cout << fixed << setprecision(9) << dp[n][n/2+1];
}
