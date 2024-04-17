#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "RMQ2"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,a[SZ],dp[SZ], stMin[30][SZ], stMax[30][SZ], s;

void buildRMQ()
{
    for(int i = 1; i <= n; i++)
    {
        stMin[0][i] = a[i];
        stMax[0][i] = a[i];
    }
    for(int j = 1; j <= 20; j++)
    {
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            stMin[j][i] = min(stMin[j-1][i],stMin[j-1][ i + (1 << (j-1)) ]);
            stMax[j][i] = max(stMax[j-1][i],stMax[j-1][ i + (1 << (j-1)) ]);
        }
    }
}

int getMax(int lo, int hi)
{
    int k = __lg(hi-lo+1);
    return max(stMax[k][lo],stMax[k][hi - (1 << k) + 1]);
}

int getMin(int lo, int hi)
{
    int k = __lg(hi-lo+1);
    return min(stMin[k][lo],stMin[k][hi - (1 << k) + 1]);
}

int main()
{
    init();
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    buildRMQ();
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + 1;
        int lo = 1, hi = i, mid, j;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            j = i - mid + 1;
            if(getMax(j,i) - getMin(j,i) <= s)
            {
                lo = mid+1;
            } else
            {
                hi = mid-1;
            }
        }
        j = i - hi + 1;
        dp[i] = min(dp[i], dp[j-1] + 1);
        //cout << i << " " << j << " " << getMax(j,i) << " " << getMin(j,i) << '\n';
    }
    cout << dp[n];
}
