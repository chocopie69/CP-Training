#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e2+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string x,y,res;
int dp[LIMIT][LIMIT];
vector<int> v1, v2;

int main()
{
    init();
    cin >> x >> y;
    int n = x.length(), m = y.length();
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for(int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(x[i-1] == y[j-1])
        {
            res = x[i-1] + res;
            v1.push_back(i);
            v2.push_back(j);
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
    cout << res << '\n';
    for(int i = v1.size()-1; i >= 0; i--)
    {
        cout << v1[i] << " ";
    }
    cout << '\n';
    for(int i = v2.size()-1; i >= 0; i--)
    {
        cout << v2[i] << " ";
    }
}

