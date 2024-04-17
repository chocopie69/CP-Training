#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 3e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s,t;
int n,m, dp[SZ][SZ];

void recur(int i, int j)
{
    if(i == 0 || j == 0) return;
    if(dp[i][j] == dp[i-1][j])
    {
        recur(i-1,j);
    } else if(dp[i][j] == dp[i][j-1])
    {
        recur(i,j-1);
    } else
    {
        recur(i-1,j-1);
        cout << s[i];
    }
}

int main()
{
    init();
    cin >> s >> t;
    n = s.length();
    m = t.length();
    s = " " + s;
    t = " " + t;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i] == t[j])
            {
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    recur(n,m);
}
