#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BANGSO"

using namespace std;

const int SZ = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

bool vis[SZ][SZ];
int n,m,a[SZ][SZ], xi[8] = {1, 0, -1, 0, 1, 1, -1, -1}, yi[8] = {0, 1, 0, -1, 1, -1, 1, -1}, cnt = 0, mx = 0;

queue<pii> qu;

void bfs(int sx, int sy)
{
    qu.push( {sx,sy} );
    vis[sx][sy] = true;
    int val = a[sx][sy], curmx = 0;
    //cout << sx << " " << sy << '\n';
    while(!qu.empty())
    {
        pii cur = qu.front();
        int x = cur.fi, y = cur.se;
        qu.pop();
        curmx++;
        for(int i = 0; i < 8; i++)
        {
            int nx = x + xi[i], ny = y + yi[i];
            if(a[nx][ny] == val && !vis[nx][ny])
            {
                vis[nx][ny] = true;
                qu.push({nx,ny});
            }
        }
    }
    if(curmx > 1)
    {
        mx = max(mx,curmx);
        cnt++;
    }
}

int main()
{
    init();
    cin >> n >> m;
    memset(a, -1, sizeof(a));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(!vis[i][j]) bfs(i,j);
        }
    }
    cout << cnt << '\n' << mx;
}

/*
5 6
1 2 1 4 5 4
1 3 1 4 5 4
3 1 2 3 3 4
2 2 4 5 3 3
2 2 3 2 1 1
*/
