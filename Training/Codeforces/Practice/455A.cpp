/// https://codeforces.com/problemset/problem/455/A

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
using namespace std;

const int INF = INT_MAX, LIMIT = 1e5+5;
const ll INFLL = 2e18;

int t;
ll n,a[LIMIT],dp[LIMIT][2],cnt[LIMIT];

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
    for(int _t = 1; _t <= 1; _t++)
    {
        memset(cnt,0,sizeof(cnt));
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        dp[0][0] = 0;
        dp[0][1] = 0;
        for(int i = 1; i <= LIMIT-5; i++)
        {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + cnt[i]*i;
        }
        cout << max(dp[LIMIT-5][0],dp[LIMIT-5][1]);
    }
}
