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

ll n,a[SZ],dp[SZ],k;

int main()
{
    init();
    cin >> n;
    k = __lg(n) + 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < (1 << k); i++)
    {
        dp[i] = a[i];
    }
    for(int i = 0; i < k; i++)
    {
        for(int mask = 0; mask < (1 << k); mask++)
        {
            if(mask >> i & 1)
            {
                dp[mask - (1 << i)] += dp[mask];
            }
        }
    }
    for(int mask = 1; mask < (1 << k); mask++)
    {
        cout << dp[mask] << ' ';
    }
}
