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

int m,n,a[SZ][SZ], res = 0, maxSize = 0, xi[4] = {1, 0, -1 , 0}, yi[4] = {0, 1, 0, -1}, curSize;
bool vis[SZ][SZ];

void dfs(int x, int y)
{
    vis[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int curX = x + xi[i], curY = y + yi[i];
        if(a[curX][curY] == 0 && !vis[curX][curY])
        {
            curSize++;
            dfs(curX, curY);
        }
    }
}

int main()
{
    init();
    memset(a, -1, sizeof(a));
    memset(vis, false, sizeof(vis));
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == 1 || vis[i][j]) continue;
            curSize = 1;
            dfs(i,j);
            maxSize = max(maxSize, curSize);
            res++;
        }
    }
    cout << res << '\n' << maxSize;
}

/*
4 5
1 0 0 0 1
0 0 0 0 1
1 0 1 1 1
1 0 0 0 0
*/

