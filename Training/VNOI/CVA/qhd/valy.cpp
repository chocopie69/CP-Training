#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "problem"

using namespace std;

const int LIMIT = 1e2+5, LIMITW = 1e4+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".ANS","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int dp[LIMIT][LIMITW],n,m, a[LIMIT], b[LIMIT],res = 0, cnt[LIMIT];
vector<int> v;

void TruyVet(int i, int j)
{
    if(i == 0 || j == 0) return;
    if(b[i] <= j && dp[i][j] == dp[i][j-b[i]] + a[i])
    {
        cnt[i]++;
        TruyVet(i,j-b[i]);
    }
    else
    {
        TruyVet(i-1,j);
    }
}

int main()
{
    init();
    memset(cnt,0,sizeof(cnt));
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i] >> a[i];
    }
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for(int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for(int j = 1; j <= m; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(b[i] <= j)
            {
                dp[i][j] = max(dp[i][j-b[i]] + a[i], dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][m] << '\n';
    TruyVet(n,m);
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] > 0)
        {
            cout << i << " " << cnt[i] << '\n';
        }
    }
}

