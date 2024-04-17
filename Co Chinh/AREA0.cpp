#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "AREA0"

using namespace std;

const int SZ = 400+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,a[SZ][SZ], sum[SZ][SZ], res;

int getSum(int i, int j, int u, int v)
{
    return sum[u][v] - sum[i-1][v] - sum[u][j-1] + sum[i-1][j-1];
}

int main()
{
    init();
    cin >> n >> m;
    memset(sum,0,sizeof(sum));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            res = 0;
            for(int k = 1; j+k-1 <= m; k++)
            {
                bool flag = false;
                int lo = 1, hi = n-i+1, mid;
                while(lo <= hi)
                {
                    mid = (lo + hi) / 2;
                    if(getSum(i,j,i + mid - 1, j + k - 1) == 0)
                    {
                        lo = mid+1;
                        flag = true;
                    } else
                    {
                        hi = mid-1;
                    }
                }
                if(flag) res = max(res,k*hi);
            }
            cout << res << " ";
        }
        cout << '\n';
    }
}

/*
3 4
0 0 1 0
0 0 0 0
0 1 0 0
*/
