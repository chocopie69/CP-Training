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

const int SZ = 2e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, p[SZ];
ll dp[SZ];

int main()
{
    init();
    cin >> n;
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j != i && (j & i) == i) p[i] |= (1 << (j-1));
        }
    }
    for(int ns = 1; ns < (1 << n); ns++)
    {
        for(int i = 1; i <= n; i++)
        {
            if( ((ns >> (i-1)) & 1) == 1 && ( ns & p[i]) == 0)
            {
                dp[ns] += dp[ ns - (1 << (i-1)) ];
            }
        }
    }
    cout << dp[ (1 << n) - 1 ];
}
