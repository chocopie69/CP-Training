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

const int SZ = 1e6+5;
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
ll a[SZ],dp[SZ], res = INFLL;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = INFLL;
    }
    dp[0] = 0;
    for(int i = 1; i <= min(4,n); i++)
    {
        dp[i] = a[i];
    }
    for(int i = 5; i <= n; i++)
    {
        for(int j = i-4; j < i; j++)
        {
            dp[i] = min(dp[i],dp[j] + a[i]);
        }
    }
    for(int i = n; i >= max(0,n-3); i--)
    {
        res = min(res,dp[i]);
    }
    cout << res;
}
