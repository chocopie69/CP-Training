#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "PALIND"

using namespace std;

const int LIMIT = 1e4+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int maxPalindrome = -INF, n;
bool dp[LIMIT][LIMIT];
string s, res = "0";

string betterRes(string x, string y)
{
    if(x.size() > y.size()) return x;
    else if(x.size() < y.size()) return y;
    else if(x > y) return x;
    return y;
}

int main()
{
    init();
    cin >> s;
    n = s.length();
    s = ' ' + s;
    for(int i = 1; i <= n; i++)
    {
        dp[i][i] = true;
        res = betterRes(res,s.substr(i,1));
    }
    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            if(len == 2)
            {
                dp[i][j] = (s[i] == s[j]);

            }
            else
            {
                dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
            }
            if(dp[i][j] && s[i] != '0')
            {
                res = betterRes(res,s.substr(i,j - i + 1));
            }
        }
    }
    cout << res.size() << '\n' << res;
}

