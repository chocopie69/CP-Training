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

string s;
int n;
ll res = 0, dp[SZ];

ll cnt(ll x)
{
    if(x <= 9) return x+1;
    return 19 - x;
}

int main()
{
    init();
    cin >> s;
    n = s.length();
    s = " " + s;
    dp[n+1] = 1;
    for(int i = n; i >= 1; i--)
    {
        dp[i] = dp[i+1]*cnt(s[i] - '0');
        if(i < n && s[i] == '1')
        {
            int x = s[i+1] - '0';
            dp[i] += dp[i+2]*cnt(10+x);
        }
        //cout << dp[i] << '\n';
    }
    cout << dp[1];
}

