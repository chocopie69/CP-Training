#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

int n,m,a[LIMIT][LIMIT], sum[LIMIT][LIMIT], res = INT_MAX;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int getSum(int u, int v, int i, int j)
{
    return sum[i][j] - sum[u-1][j] - sum[i][v-1] + sum[u-1][v-1];
}

int main()
{
    init();
    cin >> m >> n;
    memset(sum,0,sizeof(sum));
    for(int i = 1 ; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            int sum1 = getSum(1,1,i,j),
                sum2 = getSum(i+1,1,m,j),
                sum3 = getSum(1,j+1,i,n),
                sum4 = getSum(i+1,j+1,m,n);
            res = min(res,max({sum1,sum2,sum3,sum4}) - min({sum1,sum2,sum3,sum4}));
        }
    }
    cout << res;
}


