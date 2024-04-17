/// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/choosing-the-judges-7/

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
using namespace std;

const int INF = INT_MAX, LIMIT = 1e5+5;
const ll INFLL = 2e18;

int t;
ll n,a[LIMIT],dp[LIMIT];

void init()
{
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    init();
    cin >> t;
    for(int _t = 1; _t <= t; _t++)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        dp[0] = 0;
        dp[1] = a[1];
        for(int i = 2; i <= n; i++)
        {
            dp[i] = max(dp[i-1],dp[i-2] + a[i]);
        }
        cout << "Case " << _t << ": " << dp[n] << '\n';
    }
}
