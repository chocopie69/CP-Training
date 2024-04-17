#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 5e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,k, a[SZ], sum[SZ], dp[SZ][SZ];

int stMax[22][SZ],stMin[22][SZ];

void rmq()
{
    for (int i = 1; i <= n; ++i)
    {
        stMax[0][i] = a[i];
        stMin[0][i] = a[i];
    }
    for (int j = 1; (1 << j) <= n; ++j)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            stMax[j][i] = max(stMax[j - 1][i], stMax[j - 1][i + (1 << (j - 1))]);
            stMin[j][i] = min(stMin[j - 1][i], stMin[j - 1][i + (1 << (j - 1))]);
        }
    }
}

int getMax(int lo, int hi)
{
    int k = __lg(hi - lo + 1);
    return max(stMax[k][lo], stMax[k][hi - (1 << k) + 1]);
}

int getMin(int lo, int hi)
{
    int k = __lg(hi - lo + 1);
    return min(stMin[k][lo], stMin[k][hi - (1 << k) + 1]);
}

int getSum(int lo, int hi)
{
    return sum[hi] - sum[lo-1];
}

signed main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    rmq();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            dp[i][j] = INFLL;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = getMax(1,i)*i - getSum(1,i);
    }
//    for(int j = 0; j <= k; j++)
//    {
//        dp[1][j] = 0;
//    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            for(int pos = 2; pos <= i; pos++)
            {
                dp[i][j] = min(dp[i][j], dp[pos-1][j-1] + getMax(pos,i) * (i - pos + 1) - getSum(pos,i) );
            }
        }
    }
    cout << dp[n][k];
}
