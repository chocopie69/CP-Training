#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BR1"

using namespace std;

const int SZ = 5e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s;
int n;
ll dp[SZ][SZ][2];

ll f(int i, int sum, bool valid)
{
    if(i == n) return sum == 0;
    ll ans = 0;
    if(dp[i][sum][int(valid)] != -1) return dp[i][sum][int(valid)];
    if(sum + 1 >= 0 && (valid || '(' <= s[i+1]))
        ans = (ans + f(i+1,sum+1,valid || '(' < s[i+1]) ) % MOD;
    if(sum - 1 >= 0 && (valid || ')' <= s[i+1] ))
        ans = (ans + f(i+1,sum-1,valid || ')' < s[i+1]) ) % MOD;
    return dp[i][sum][int(valid)] = ans;
}

int main()
{
    init();
    cin >> s;
    n = s.length();
    s = " " + s;
    memset(dp,-1,sizeof(dp));
    cout << f(0,0,false);
}
