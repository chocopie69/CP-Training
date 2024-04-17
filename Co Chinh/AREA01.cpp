#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "AREA01"

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

int m,n,u,v, xi[4] = {1, 0 , -1, 0}, yi[4] = {0, 1, 0 , -1}, a[SZ][SZ];
char c[SZ][SZ];
bool vis[SZ][SZ];
queue<pii> qu;

int bfs(int sX, int sY, int num)
{
    vis[sX][sY] = true;
    qu.push({sX,sY});
    int cnt = 1;
    while(!qu.empty())
    {
        int x = qu.front().fi;
        int y = qu.front().se;
        qu.pop();
        for(int i = 0; i < 4; i++)
        {
            int curX = x + xi[i], curY = y + yi[i];
            if(vis[curX][curY] || a[curX][curY] != num) continue;
            vis[curX][curY] = true;
            cnt++;
            qu.push({curX,curY});
        }
    }
    return cnt;
}

int res(int x)
{
    memset(vis,false,sizeof(vis));
    int cnt = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(vis[i][j] || a[i][j] != x) continue;
            cnt = max(cnt,bfs(i,j, x));
        }
    }
    return cnt;
}

int main()
{
    init();
    memset(a, -1, sizeof(a));
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            a[i][j] = int(c[i][j]) - 48;
        }
    }
    cout << max(res(0), res(1));
    //cout << res(1);
}
