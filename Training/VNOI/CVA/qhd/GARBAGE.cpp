#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int m,n,a[LIMIT][LIMIT],dp[LIMIT][LIMIT], res = -INF,i2,j2;
vector<int> v;

int main()
{
    init();
    cin >> m >> n;
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = max({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]}) + a[i][j];
        }
    }
    for(int j = 1; j <= n; j++)
    {
        res = max(res, dp[m][j]);
        if(res == dp[m][j])
            j2 = j;
    }
    cout << res << '\n';
    int i = m, j = j2;
    while(i > 0)
    {
        v.push_back(j);
        if(dp[i][j] == dp[i-1][j-1] + a[i][j])
        {
            j--;
        }
        else if(dp[i][j] == dp[i-1][j+1] + a[i][j])
        {
            j++;
        }
        i--;
    }
    for(int i = v.size()-1; i >= 0; i--)
    {
        cout << v[i] << '\n';
    }
}

