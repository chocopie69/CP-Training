#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXMN = 2*1e3+2;
int m,n;
ll a[MAXMN][MAXMN],verticalSum[MAXMN],horizontalSum[MAXMN],diagonalDownSum[MAXMN],diagonalUpSum[MAXMN];

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("QUEEN.INP","r",stdin);
    freopen("QUEEN.OUT","w",stdout);
    memset(verticalSum,0,sizeof(verticalSum));
    memset(horizontalSum,0,sizeof(horizontalSum));
    memset(diagonalDownSum,0,sizeof(diagonalDownSum));
    memset(diagonalUpSum,0,sizeof(diagonalUpSum));
}

void createSumArrays()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            horizontalSum[i] += a[i][j];
            verticalSum[j] += a[i][j];
            diagonalDownSum[i-j+n-1] += a[i][j];
            diagonalUpSum[i+j] += a[i][j];
        }
    }
}

void solve()
{
    ll res = -1e18;
    if(m == 1)
    {
        cout << horizontalSum[0];
        return;
    }
    if(n == 1)
    {
        cout << verticalSum[0];
        return;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            ll cur = verticalSum[j] + horizontalSum[i] + diagonalDownSum[i-j+n-1] + diagonalUpSum[i+j] - a[i][j]*3;
            /*if((i == 0 && j == 0) || (i == 0 && j == n-1) || (i == m-1 && j == 0) || (i == m-1 && j == n-1) || (i == 2 && j == 1))
            {
                cout << i << " " << j << " " << cur << endl;
            }
            */
            res = max(res,cur);
        }
    }
    cout << res;
}

int main()
{
    init();
    cin >> m >> n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    createSumArrays();
    solve();
}
