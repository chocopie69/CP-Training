#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "problem"

using namespace std;

const int LIMIT = 1e2+5, LIMITW = 1e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".ANS","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll dp[LIMIT][LIMITW],n,m, a[LIMIT], b[LIMIT],res = 0;
vector<int> v;

void TruyVet(int i, int j)
{
    if(i == 0 || j == 0) return;
    if(b[i] <= j && dp[i][j] == dp[i-1][j-b[i]] + a[i])
    {
        v.push_back(i);
        TruyVet(i-1,j-b[i]);
    }
    else
    {
        TruyVet(i-1,j);
    }
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
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
            if(a[i] <= j)
            {
                dp[i][j] = max(dp[i-1][j-a[i]] + b[i], dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][m] << '\n';
    /*TruyVet(n,m);
    for(int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }*/
}
