#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

ll n,k, a[SZ];

namespace sub1
{
    ll dp[SZ];
    void solve()
    {
        for(int i = 1; i <= k; i++)
        {
            int lo,hi;
            cin >> lo >> hi;
            a[lo]++;
            a[hi+1]--;
        }
        for(int i = 1; i <= n; i++)
        {
            a[i] += a[i-1];
        }
        dp[0] = 1;
        for(int i = 1; i < n; i++)
        {
            dp[i] = 0;
            for(int j = 1; j <= n; j++)
            {
                if(i - j < 0 || a[j] == 0) continue;
                dp[i] = (dp[i] + dp[i-j]) % MOD;
            }
        }
        cout << dp[n-1];
    }
}

int main()
{
    init();
    cin >> n >> k;
    sub1::solve();
}

