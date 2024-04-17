#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "timduongdi"

using namespace std;

const int SZ = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,sx,sy,tx,ty, xi[4] = {1,0,-1,0}, yi[4] = {0,1,0,-1} ;
ll a[SZ][SZ] ;

bool vis[SZ][SZ];
queue<pii> qu;

bool invalid(int x, int y)
{
    return x > n || x < 1 || y > m || y < 1;
}

void bfs(int sx, int sy, ll val)
{
    memset(vis,false,sizeof(vis));
    qu.push({sx,sy});
    vis[sx][sy] = true;
    while(!qu.empty())
    {
        pii u = qu.front();
        qu.pop();
        int x = u.fi, y = u.se;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + xi[i], ny = y + yi[i];
            if(vis[nx][ny] || abs(a[nx][ny] - a[x][y] ) > val || invalid(nx,ny) ) continue;
            qu.push({nx,ny});
            vis[nx][ny] = true;
        }
    }
}

int main()
{
    init();
    cin >> n >> m >> sx >> sy >> tx >> ty;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    ll lo = 0, hi = 4e9+1, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        bfs(sx,sy, mid);
        if(vis[tx][ty])
        {
            hi = mid-1;
        } else
        {
            lo = mid+1;
        }
    }
    cout << lo;
}

/*
3 4
1 1 3 3
-2 9 3 4
0 3 7 -4
8 -9 9 10
*/
