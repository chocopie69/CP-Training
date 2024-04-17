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

int t,n,k;
ll dp[1 << SZ][SZ], res = 0;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        res = 0;
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < n; i++)
        {
            dp[(1 << i)][i] = 1;
        }
        for(int mask = 1; mask < (1 << n); mask++)
        {
            int cnt = 0;
            for(int i = 0; i < n; i++)
            {
                if(mask >> i & 1) cnt++;
            }
            if(cnt < 2) continue;
            for(int i = 0; i < n; i++)
            {
                if((mask >> i) & 1)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(abs(i-j) >= k && j != i && (mask >> j) & 1) dp[mask][i] += dp[mask - (1 << i)][j];
                    }
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            res += dp[ (1 << n) - 1 ][i];
        }
        cout << res << '\n';
    }

}
