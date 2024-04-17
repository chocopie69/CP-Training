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

int n, a[SZ], b[SZ], dp[SZ][2];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    dp[1][0] = b[1];
    dp[1][1] = a[1];
    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = max( dp[i-1][0] + abs(a[i] - a[i-1]) + b[i], dp[i-1][1] + abs(a[i] - b[i-1]) + b[i] );
        dp[i][1] = max( dp[i-1][0] + abs(b[i] - a[i-1]) + a[i], dp[i-1][1] + abs(b[i] - b[i-1]) + a[i] );
    }
    cout << max(dp[n][0],dp[n][1]);
}
