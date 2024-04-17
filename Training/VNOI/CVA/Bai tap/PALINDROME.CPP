#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 5e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,dp[LIMIT][LIMIT];
string s,s2;

int main()
{
    init();
    cin >> n >> s;
    s2 = s;
    reverse(s2.begin(),s2.end());
    n = s.length();
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for(int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }
    //cout << s << " " << s2 << '\n';
    s = ' ' + s;
    s2 = ' ' + s2;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = max({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + (s[i] == s2[j]) });
            //if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    cout << n-dp[n][n];
}
