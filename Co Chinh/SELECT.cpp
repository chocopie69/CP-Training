#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SELECT"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,a[SZ],b[SZ],dp[SZ][4];

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
    dp[0][1] = 0;
    dp[1][1] = max(a[1],0LL);
    dp[0][2] = 0;
    dp[1][2] = max(b[1],0LL);
    for(int i = 2; i <= n; i++)
    {
        dp[i][1] = max({ dp[i-1][2],dp[i-2][1],dp[i-2][2] }) + max(a[i],0LL);
        dp[i][2] = max({ dp[i-1][1],dp[i-2][1],dp[i-2][2] }) + max(b[i],0LL);
    }
    cout << max(dp[n][1], dp[n][2] );
}

/*
8
4 2 -1 6 -3 1 5 4
2 -1 3 2 -5 -6 7 5
*/
