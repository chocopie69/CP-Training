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

const int SZ = 21;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m, a[SZ], b[SZ];
pll dp[1 << SZ];

int main()
{
    init();
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for(int mask = 0; mask < (1 << m); mask++)
    {
        dp[mask] = {0, a[0]};
        for(int i = 0; i < m; i++)
        {
            if(mask >> i & 1)
            {
                int mask2 = mask - (1 << i);
                if(b[i] > dp[mask2].se) continue;
                int x = dp[mask2].fi, y = dp[mask2].se;
                y -= b[i];
                if(y == 0)
                {
                    x++;
                    y = a[x];
                }
                if(x == n)
                {
                    cout << "YES";
                    return 0;
                }
                if(x >= dp[mask].fi)
                {
                    dp[mask] = {x,y};
                }
            }
        }
    }
    cout << "NO";
}

