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

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s;
ll sum[SZ], dp[SZ], n = 0, a[SZ], mx[4];

int main()
{
    init();
    cin >> s;
    sum[0] = 0;
    dp[0] = 0;
    memset(mx,-1,sizeof(mx));
    mx[0] = 0;
    for(char c : s)
    {
        n++;
        a[n] = int(c) - 48;
        sum[n] = sum[n-1] + a[n];
    }
    for(int i = 1; i <= n; i++)
    {
        dp[i] = dp[i-1];
        int cur = sum[i] % 3;
        if(mx[ cur ] != -1)
        {
            dp[i] = max(dp[i], dp[mx[cur]] + 1);
        }
        mx[cur] = i;
    }
    cout << dp[n];
}
