#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 3e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, a[SZ][SZ], xi[4] = {1,0,-1,0}, yi[4] = {0,1,0,-1};
bool vis[SZ][SZ];

queue<pair<pii,pii>> qu;

bool invalid(int x, int y)
{
    return x < 1 || x > n || y < 1 || y > n;
}

void bfs(int sx, int sy)
{
    vis[sx][sy] = true;
    qu.push( { {sx,sy}, {0, 0} } );
    while(!qu.empty())
    {
        pii u = qu.front().fi, prev = qu.front().se;
        qu.pop();
        int x = u.fi, y = u.se, prevx = prev.fi, prevy = prev.se;
        //cout << x << " " << y << " " << prevx << " " << prevy << '\n';
        for(int i = 0; i < 4; i++)
        {
            int nx = x + xi[i], ny = y + yi[i];
            //cout << x << " " << y << " " << prevx << " " << prevy << " " << nx << " " << ny << '\n';
            if(a[nx][ny] == 1 || invalid(nx,ny) || (nx == prevx && ny == prevy) ) continue;
            if(vis[nx][ny] == true)
            {
                cout << "No";
                //cout << '\n' << sx << " " << sy << " " << x << " " << y << " " << nx << " " << ny << " " << prevx << " " << prevy << '\n';
                exit(0);
            }
            qu.push({ {nx,ny}, {x,y} });
            vis[nx][ny] = true;
        }
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = int(c) - 48;
            //cout << a[i][j] << " ";
        }
        //cout << '\n';
    }
    memset(vis,false,sizeof(vis));
    bfs(1,1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == 1 || vis[i][j] ) continue;
            bfs(i,j);
        }
        cout << '\n';
    }
    cout << "Yes";
}
