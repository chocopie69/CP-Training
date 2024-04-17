#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMITN = 1e2+5, LIMITS = 1e4+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n,s,a[LIMITN],dp[LIMITN][LIMITS], cnt[LIMITN];

void recur(int i, int j)
{
    if(i == 0 || j == 0) return;
    if(dp[i][j] != dp[i-1][j])
    {
        recur(i,j - a[i]);
        cnt[i]++;
    }
    else
    {
        recur(i-1, j);
    }
}

int main()
{
    init();
    memset(cnt,0,sizeof(cnt));
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int j = 1; j <= s; j++)
    {
        dp[0][j] = INF;
    }
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for(int j = 1; j <= s; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(a[i] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j],dp[i][j-a[i]] + 1);
            }
        }
    }
    cout << dp[n][s] << '\n';
    recur(n,s);
    for(int i = 1; i <= n; i++)
    {
        cout << cnt[i] << " ";
    }
}

