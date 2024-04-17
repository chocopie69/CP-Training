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

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 5e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int r,c,m;
#define bs bitset<500>
bs a[SZ], dp[SZ][2];
string s;
int res = 0;

int main()
{
    init();
    cin >> r >> c >> m;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            char p;
            cin >> p;
            if(p == '.')
            {
                a[i][j] = 1;
                dp[i][0][j] = 1;
            }
        }
    }
    cin >> s;
    s = " " + s;
    for(int k = 1; k <= m; k++)
    {
        int j = k % 2;
        for(int i = 0; i < r; i++)
        {
            dp[i][j] = 0;
            if(i > 0 && ( s[k] == 'S' || s[k] == '?' )) dp[i][j] |= ( a[i] & dp[i - 1][j ^ 1] );
            if(i < r - 1 && ( s[k] == 'N' || s[k] == '?' )) dp[i][j] |= ( a[i] & dp[i + 1][j ^ 1] );
            if( s[k] == 'E' || s[k] == '?' ) dp[i][j] |= ( a[i] & (dp[i][j ^ 1] << 1) );
            if( s[k] == 'W' || s[k] == '?' ) dp[i][j] |= ( a[i] & (dp[i][j ^ 1] >> 1) );
        }
    }
    for(int i = 0; i < r; i++)
    {
        res += dp[i][ m % 2 ].count();
        //cout << dp[i][m % 2].count() << '\n';
    }
    cout << res;
}

