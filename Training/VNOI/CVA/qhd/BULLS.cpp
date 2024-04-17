#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 2111992, INFLL = 2e18;

ll n,k,dp[LIMIT];

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    init();
    cin >> n >> k;
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i <= k + 1)
        {
            dp[i] = (i+1) % MOD;
        }
        else
        {
            dp[i] = (dp[i-1] + dp[i-k-1]) % MOD;
        }
    }
    cout << dp[n];
}

