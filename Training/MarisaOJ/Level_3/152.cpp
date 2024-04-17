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

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n;
ll dp[SZ][SZ];
string s;

int main()
{
    init();
    cin >> s;
    n = s.length();
    s = " " + s;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if( s[i] != ')' && j > 0)
            {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            }
            if( s[i] != '(' && j < n)
            {
                dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
            }
        }
    }
    cout << dp[n][0];
}
