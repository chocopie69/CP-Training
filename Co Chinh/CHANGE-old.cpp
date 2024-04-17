#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CHANGE"

using namespace std;

const int SZ = 1e2+5, SZ2 = 1e7+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int s,n,a[SZ],sum = 0, res = INF, dp[SZ2];

int main()
{
    init();
    cin >> s >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i <= 2*s; i++)
    {
        dp[i] = INF;
    }
    dp[0] = 0;
    for(int j = 1; j <= 2*s; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(a[i] <= j)
            {
                dp[j] = min(dp[j],dp[j-a[i]] + 1);
            }
        }
    }
    for(int j = s; j <= 2*s; j++)
    {
        res = min(res,dp[j] + dp[j-s]);
    }
    cout << res;
}
