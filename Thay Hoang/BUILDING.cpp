#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "BUILDING"

using namespace std;

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int m,n,a[SZ][SZ], maxUp[SZ][SZ], maxDown[SZ][SZ], maxLeft[SZ][SZ], maxRight[SZ][SZ], res = 0;

void preCompute()
{
    for(int i = 1; i <= m; i++)
    {
        maxLeft[i][1] = a[i][1];
        for(int j = 2; j <= n; j++)
        {
            maxLeft[i][j] = max(maxLeft[i][j-1],a[i][j]);
        }
        maxRight[i][n] = a[i][n];
        for(int j = n-1; j >= 1; j--)
        {
            maxRight[i][j] = max(maxRight[i][j+1],a[i][j]);
        }
    }
    for(int j = 1; j <= n; j++)
    {
        maxUp[1][j] = a[1][j];
        for(int i = 2; i <= m; i++)
        {
            maxUp[i][j] = max(maxUp[i-1][j],a[i][j]);
        }
        maxDown[m][j] = a[m][j];
        for(int i = m-1; i >= 1; i--)
        {
            maxDown[i][j] = max(maxDown[i+1][j],a[i][j]);
        }
    }
}

int main()
{
    init();
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    preCompute();
    for(int i = 2; i < m; i++)
    {
        for(int j = 2; j < n; j++)
        {
            if(maxUp[i][j] > a[i][j] && maxDown[i][j] > a[i][j] && maxLeft[i][j] > a[i][j] && maxRight[i][j] > a[i][j])
            {
                //cout << i << ' ' << j << '\n';
                res++;
            }
        }
    }
    cout << res;
}

