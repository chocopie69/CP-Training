#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "MATRIX"

using namespace std;

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m;
ll a[SZ][SZ], sum[SZ][SZ], b[SZ], minNum, x, res = 0;

ll getSum(int i, int j, int u, int v)
{
    return sum[u][v] - sum[i-1][v] - sum[u][j-1] + sum[i-1][j-1];
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    for(int h1 = 1; h1 <= m; h1++)
    {
        for(int h2 = h1; h2 <= m; h2++)
        {
            minNum = 0;
            ll curSum = 0;
            for(int i = 1; i <= n; i++)
            {
                x = getSum(i,h1,i,h2);
                curSum += x;
                res = max(res, curSum - minNum);
                minNum = min(minNum,curSum);
            }
        }
    }
    cout << res;
}
