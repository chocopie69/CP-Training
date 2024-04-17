#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "D"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin);
    freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 4e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

ll n,k, dp[SZ][SZ];

void preCalc()
{
    dp[0][0] = 1;
    for(int j = 1; j <= 4000; j++)
    {
        for(int i = 0; i <= 4000; i++)
        {
            if(i > 0) dp[i][j] += dp[i-1][j-1];
            if(i < 4000) dp[i][j] += dp[i+1][j-1];
        }
    }
//    for(int j = 0; j <= 12; j++)
//    {
//        for(int i = 0; i <= 12; i++)
//        {
//            cout << j << " " << i << " " << dp[i][j] << '\n';
//        }
//    }
}

ll t, a[SZ];

int main()
{
    init();
    preCalc();
    while(cin >> t)
    {
        if(t == -1) break;
        if(t == 1)
        {
            cin >> n >> k;
            n *= 2;
            int x = 0;
            for(int i = 1; i <= n; i++)
            {
                //if(x < 0) return 0;
                if(dp[x+1][n - i] >= k)
                {
                    x++;
                    a[i] = 1;
                }
                else
                {
                    k -= dp[x+1][n - i];
                    x--;
                    a[i] = -1;
                }
            }
            for(int i = 1; i <= n; i++)
            {
                if(a[i] == 1) cout << i << " ";
            }
            for(int i = 1; i <= n; i++)
            {
                if(a[i] == -1) cout << i << " ";
            }
            cout << '\n';
        } else
        {
            cin >> n;
            n *= 2;
            int sum = 0;
            ll res = 1;
            for(int i = 1; i <= n; i++)
            {
                int x;
                cin >> x;
                a[x] = (i <= n/2 ? 1 : -1);
            }
            for(int i = 1; i <= n; i++)
            {
                sum += a[i];
                if(a[i] == -1 && sum != n/2-1) res += dp[sum+2][n - i];
            }
            cout << res << '\n';
        }
    }
}

/*
1 2000 1
1 2000 2
1 2000 3
1 2000 4
1 2000 5
1 2000 6
1 5 7
1 5 8
1 5 9
1 5 10
1 5 11
1 5 12
1 5 13
1 5 14
-1
*/

