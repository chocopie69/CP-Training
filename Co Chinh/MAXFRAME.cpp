#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "MAXFRAME"

using namespace std;

const int LIMIT = 405;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n, m , a[LIMIT][LIMIT], sumRow[LIMIT][LIMIT], sumCol[LIMIT][LIMIT], res = -INFLL, minSum;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        sumRow[i][0] = 0;
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sumRow[i][j] = sumRow[i][j-1] + a[i][j];
        }
    }
    for(int j = 1; j <= m; j++)
    {
        sumCol[j][0] = 0;
        for(int i = 1; i <= n; i++)
        {
            sumCol[j][i] = sumCol[j][i-1] + a[i][j];
        }
    }
    for(int l = 1; l < n; l++)
    {
        for(int h = l + 1; h <= n; h++)
        {
            int j;
            ll mx = sumCol[1][h] - sumCol[1][l-1] - sumRow[l][1] - sumRow[h][1];
            for(int i = 2; i <= m; i++)
            {
                res = max(res, sumRow[l][i-1] + sumRow[h][i-1] + sumCol[i][h] - sumCol[i][l-1] + mx );
                j = i;
                mx = max(mx, sumCol[j][h] - sumCol[j][l-1] - sumRow[l][j] - sumRow[h][j]);
            }
            //cout << '\n';
        }
    }
    cout << res;
}

