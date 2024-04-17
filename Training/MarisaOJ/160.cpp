#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n;
ll a[SZ], b[SZ], dp[SZ][3][3];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= 2; j++)
        {
            if(j >= 1)
            {
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-1][0] + a[i]);
                dp[i][0][j] = max(dp[i][0][j], dp[i-1][0][j-1] + b[i]);
            }
            dp[i][1][0] = max(dp[i][1][0], dp[i-1][0][j] + a[i]);
            dp[i][0][1] = max(dp[i][0][1], dp[i-1][j][0] + b[i]);
        }
    }
    ll res = 0;
    for(int j = 0; j <= 2; j++)
    {
        res = max({res, dp[n][j][0], dp[n][0][j] });
    }
    cout << res;
}

