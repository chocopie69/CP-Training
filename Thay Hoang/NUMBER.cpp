#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NUMBER"

using namespace std;

const int SZ = 3e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

string s, t;
int n,m;
pair<int,char> dp[SZ][SZ], res = {0,' '};

int main()
{
    init();
    cin >> s >> t;
    n = s.length();
    m = t.length();
    reverse(all(s));
    reverse(all(t));
    s = " " + s;
    t = " " + t;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            dp[i][j] = {0,' '};
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i] == t[j])
            {
                dp[i][j] = {dp[i-1][j-1].first + 1, s[i]};
                if(s[i] != '0')
                {
                    res = max(res, dp[i][j]);
                }
            } else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    if(res.fi == 0)
    {
        cout << 0;
        return 0;
    }
    int i = n, j = m;
    char x = res.se;
    while(i > 0 && j > 0 && x != ' ')
    {
        while(s[i] != x) i--;
        while(t[j] != x) j--;
        cout << s[i];
        i--;
        j--;
        x = dp[i][j].se;
    }
}
