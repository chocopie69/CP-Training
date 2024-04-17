#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CHOCOLATE"

using namespace std;

const int SZ = 1e2+5;
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
int n, start = -1;
ll sum[SZ], dp[SZ];

int main()
{
    init();
    cin >> s;
    n = s.length();
    s = " " + s;
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + int(s[i] == 'X');
        if(start == -1 && s[i] == 'X')
        {
            start = i;
        }
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(sum[i]-sum[j] == 1)
            {
                dp[i] += dp[j];
            }
        }
    }
    cout << dp[n];
}
