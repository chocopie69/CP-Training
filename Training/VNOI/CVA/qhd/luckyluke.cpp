#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 13051984, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n,k,x,dp[LIMIT];
map<int,bool> mp;

int main()
{
    init();
    cin >> n >> k;
    while(k--)
    {
        cin >> x;
        mp[x] = true;
    }
    dp[0] = 1;
    dp[1] = (mp[1] == false);
    for(int i = 2; i <= n; i++)
    {
        dp[i] = (mp[i] == true ? 0 : dp[i-1] + dp[i-2]);
        dp[i] %= MOD;
    }
    cout << dp[n];
}

