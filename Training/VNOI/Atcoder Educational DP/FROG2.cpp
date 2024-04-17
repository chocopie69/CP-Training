#include <bits/stdc++.h>
#define ll long long
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

int n,k,a[SZ],dp[SZ];

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = INF;
    }
    dp[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        for(int j = i-1; j >= max(1,i-k); j--)
        {
            dp[i] = min(dp[i],dp[j] + abs(a[i] - a[j]));
        }
    }
    cout << dp[n];
}