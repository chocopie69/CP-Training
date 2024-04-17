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

const int SZ = 16;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll dp[1 << SZ][SZ],n,a[SZ], cnt[1 << SZ][SZ];

int main()
{
    init();
    while(cin >> n)
    {
        if(n == 0) break;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        for(int mask = 1; mask < (1 << n); mask++)
        {
            for(int i = 0; i < n; i++)
            {
                if(mask >> i & 1)
                {
                    int mask2 = mask - (1 << i);
                    if(mask2 == 0)
                    {
                        dp[mask][i] = a[i]*2;
                        cnt[mask][i] = 1;
                    } else
                    {
                        for(int j = 0; j < n; j++)
                        {
                            if(mask2 >> j & 1)
                            {
                                if(dp[mask][i] == dp[mask2][j] - a[j] + abs(a[i]-a[j]) + a[i])
                                {
                                    cnt[mask][i] += cnt[mask2][j];
                                }
                                if(dp[mask][i] < dp[mask2][j] - a[j] + abs(a[i]-a[j]) + a[i])
                                {
                                    dp[mask][i] = dp[mask2][j] - a[j] + abs(a[i]-a[j]) + a[i];
                                    cnt[mask][i] = cnt[mask2][j];
                                }
                            }
                        }
                    }
                }
            }
        }
        int mx = 0, res = 0;
        for(int i = 0; i < n; i++)
        {
            if(dp[ (1 << n) - 1 ][i] == mx)
            {
                res += cnt[ (1 << n) - 1 ][i];
            }
            if(dp[ (1 << n) - 1 ][i] > mx)
            {
                mx = dp[ (1 << n) - 1 ][i];
                res = cnt[ (1 << n) - 1 ][i];
            }
        }
        cout << mx + 2*n << " " << res << '\n';
    }
}
