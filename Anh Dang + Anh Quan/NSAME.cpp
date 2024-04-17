#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NSAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll a,b, dp[20][2][10][2];
string s;
int n;

string toString(ll k)
{
    ostringstream oss;
    oss << k;
    return " " + oss.str();
}

ll f(int i, bool valid, int prev, bool nz)
{
    if(i == n) return 1LL;
    ll ans = 0;
    if(dp[i][int(valid)][prev][int(nz)] != -1) return dp[i][int(valid)][prev][int(nz)];
    for(char c = '0'; c <= '9'; ++c)
    {
        if( (valid|| c <= s[i+1]) && ((c - '0') != prev || !nz) )
            ans += f(i+1, valid || c < s[i+1], c - '0', nz || c != '0');
    }
    return dp[i][int(valid)][prev][int(nz)] = ans;
}

int main()
{
    init();
    cin >> a >> b;
    s = toString(a-1);
    n = s.length() - 1;
    memset(dp,-1,sizeof(dp));
    ll val1 = f(0,false,0,false);
    memset(dp,-1,sizeof(dp));
    s = toString(b);
    n = s.length() - 1;
    ll val2 = f(0,false,0,false);
    cout << val2 - val1;
}
