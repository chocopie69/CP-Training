#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,a[SZ][SZ], sum[SZ][SZ], b[SZ][SZ];

ll getSum(ll i, ll j, ll u, ll v)
{
    return sum[u][v] - sum[u][j-1] - sum[i-1][v] + sum[i-1][j-1];
}

void rotate90()
{
    int curI = 0, curJ;
    for(int i = 1; i <= m; i++)
    {
        curI++;
        curJ = n;
        for(int j = 1; j <= n; j++)
        {
            a[i][j] = b[curJ][curI];
            curJ--;
        }
    }
    swap(n,m);
    memset(sum, 0, sizoef(sum));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
}

bool solve(string x, string y)
{
    for(int i = 1; i < n; i++)
    {
        if(sum[i][m] * 2 == sum[n][m] - sum[i][m])
        {
            for(int j = i + 1; j < n; j++)
            {
                if(sum[n][m] - sum[j][m] == sum[i][m])
                {
                    cout << "YES" << '\n' << x << i << '\n' << x << j;
                    return true;
                }
            }
            for(int j = 1; j < m; j++)
            {
                if(getSum(i+1,1,n,j) == sum[i][m])
                {
                    cout << "YES" << '\n' << x << i << '\n' << y << (y == "D" ? j : m-j);
                    return true;
                }
            }
        } else if(sum[i][m] == (sum[n][m] - sum[i][m]) * 2)
        {
            for(int j = 1; j < m; j++)
            {
                if(getSum(1,1,i,j) == getSum(i+1,1,n,m))
                {
                    cout << "YES" << '\n' << x << i << '\n' << y << (y == "D" ? j : m-j);
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    if(solve("N ", "D "))
        return 0;
    rotate90();
    if(solve("D ", "N "))
        return 0;
    cout << "NO";
}

/*
3 4
3 8 1 -6
2 -3 2 2
-1 8 1 1

4 3
-1 2 3
8 -3 8
1 2 1
1 2 -6

3 3
0 20 19
4 0 5
7 8 9

2 2
-8 6
10 -3
*/
