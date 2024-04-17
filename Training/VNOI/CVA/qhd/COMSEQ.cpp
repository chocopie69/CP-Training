#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e3+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n,m,a[LIMIT],b[LIMIT], dp[LIMIT][LIMIT];
vector<int> v1, v2, v3;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 0; i <= n; i++)
    {
        if(i > 0)
            cin >> a[i];
        dp[i][0] = 0;
    }
    for(int j = 0; j <= m; j++)
    {
        if(j > 0)
            cin >> b[j];
        dp[0][j] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[n][m] << '\n';
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(a[i] == b[j])
        {
            v1.push_back(a[i]);
            v2.push_back(i);
            v3.push_back(j);
            i--;
            j--;
        }
        else if(dp[i][j] == dp[i-1][j])
        {
            i--;
        }
        else if(dp[i][j] == dp[i][j-1])
        {
            j--;
        }
    }
    for(int i = v1.size() - 1; i >= 0; i--)
    {
        cout << v1[i] << " ";
    }
    cout << '\n';
    for(int i = v2.size() - 1; i >= 0; i--)
    {
        cout << v2[i] << " ";
    }
    cout << '\n';
    for(int i = v3.size() - 1; i >= 0; i--)
    {
        cout << v3[i] << " ";
    }
}

