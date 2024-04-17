#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int a,b,c, d[SZ][SZ];
bool vis[SZ][SZ];
queue<pii> qu;

int bfs()
{
    d[0][0] = 0;
    vis[0][0] = true;
    qu.push({0,0});
    while(!qu.empty())
    {
        int x = qu.front().fi, y = qu.front().se;
        qu.pop();
        if(x == c || y == c)
        {
            return d[x][y];
        }
        if(!vis[a][y])
        {
            qu.push({a,y});
            vis[a][y] = true;
            d[a][y] = d[x][y] + 1;
        }
        if(!vis[x][b])
        {
            qu.push({x,b});
            vis[x][b] = true;
            d[x][b] = d[x][y] + 1;
        }
        if(!vis[x][0])
        {
            qu.push({x,0});
            vis[x][0] = true;
            d[x][0] = d[x][y] + 1;
        }
        if(!vis[0][y])
        {
            qu.push({0,y});
            vis[0][y] = true;
            d[0][y] = d[x][y] + 1;
        }
        if(y >= (a-x) && !vis[a][y - (a-x) ] )
        {
            vis[a][y - (a-x) ] = true;
            qu.push({a, y - (a-x)});
            d[a][y - (a-x)] = d[x][y] + 1;
        }
        if(x >= (b-y) && !vis[x - (b-y)][b] )
        {
            vis[x - (b-y)][b] = true;
            qu.push({ x - (b-y), b });
            d[x - (b-y)][b] = d[x][y] + 1;
        }
        if(x + y <= a && !vis[x+y][0])
        {
            vis[x+y][0] = true;
            d[x+y][0] = d[x][y] + 1;
            qu.push({x+y, 0});
        }
        if(x + y <= b && !vis[0][x+y])
        {
            vis[0][x+y] = true;
            d[0][x+y] = d[x][y] + 1;
            qu.push({0, x+y});
        }
    }
    return -1;
}

int main()
{
    init();
    cin >> a >> b >> c;
    cout << bfs();
}
