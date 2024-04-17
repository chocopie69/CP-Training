#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int LIMIT = 1005;
int n,m,k,a[LIMIT][LIMIT],b[LIMIT][LIMIT],sum[LIMIT][LIMIT],res=1;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LANDVAL.INP","r",stdin);
    freopen("LANDVAL.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    int left = 1,right = 1e6,mid;
    bool found;
    while(left <= right)
    {
        memset(sum,0,sizeof(sum));
        found = false;
        mid = (left+right)/2;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                b[i][j] = (a[i][j] >= mid);
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + b[i][j];
            }
        }
        for(int i=1;i<=n-k+1;i++)
        {
            for(int j=1;j<=m-k+1;j++)
            {
                int u = i+k-1, v = j+k-1;
                if(sum[u][v] - sum[u][j-1] - sum[i-1][v] + sum[i-1][j-1] == k*k)
                {
                    res = max(res,mid);
                    found = true;
                }
            }
        }
        if(found)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    cout << res;
}
