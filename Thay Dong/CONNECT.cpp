#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "PATH"

using namespace std;

const int SZ = 500+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;
const int LIM = 10;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m,q, xi[4] = {1,0,-1,0}, yi[4] = {0,1,0,-1}, a[SZ][SZ], d[2][SZ][SZ];
char c;
queue<pii> qu[9005];

bool inside(int i, int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

void preCalc(int dir, int p)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            d[dir][i][j] = INF;
        }
    }
    //memset(d, 0x3f, sizeof d );
    int h = (dir == 0 ? 1 : m);
    for(int i = 1; i <= n; i++)
    {
        d[dir][i][h] = 0;
        qu[0].push( {i,h} );
    }
    int cnt = n;
    for(int pos = 0; pos <= 9*(m+n); pos++)
    {
        while(!qu[pos].empty())
        {
            //pos++;
            pii u = qu[pos].front();
            qu[pos].pop();
            cnt--;
            int i = u.fi, j = u.se;
            if(d[dir][i][j] != pos) continue;
            for(int k = 0; k < 4; k++)
            {
                int x = i + xi[k], y = j + yi[k];
                if(!inside(x,y)) continue;
                int w = abs(a[i][j] - p);
                //cout << i << " " << j << " - " << x << " " << y << " - " << w << '\n';
                if(d[dir][x][y] > d[dir][i][j] + w)
                {
                    d[dir][x][y] = d[dir][i][j] + w;
                    qu[ d[dir][x][y] ].push( {x,y} );
                    cnt++;
                }
            }
        }
    }
}

struct Node
{
    int i,j,lf,rt;
    Node(int _i = 0, int _j = 0, int _lf = 0, int _rt = 0) : i(_i), j(_j), lf(_lf), rt(_rt) {}
};

queue<Node> nodes[9005];

int dist[SZ][SZ][2][2];

void calcDist(int p)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dist[i][j][0][0] = INF;
            dist[i][j][0][1] = INF;
            dist[i][j][1][0] = INF;
            dist[i][j][1][1] = INF;
        }
    }
    //memset(dist, 0x3f, sizeof dist);
    int cnt = 0;
    for(int j = 1; j <= m; j++)
    {
        nodes[ abs(a[1][j] - p) ].push({1, j, 0, 0});
        dist[1][j][0][0] = abs(a[1][j] - p);
        cnt++;
    }
    for(int pos = 0; pos <= 9*(m+n); pos++)
    {
        while(!nodes[pos].empty())
        {
            //pos++;
            Node u = nodes[pos].front();
            nodes[pos].pop();
            cnt--;
            int i = u.i, j = u.j, lf = u.lf, rt = u.rt, curd = pos;
            if(curd != dist[i][j][lf][rt]) continue;
            if(lf == 0 && dist[i][j][1][rt] > curd + d[0][i][j] )
            {
                dist[i][j][1][rt] = curd + d[0][i][j];
                nodes[ (dist[i][j][1][rt]) ].push( {i,j,1,rt} );
                cnt++;
            }
            if(rt == 0 && dist[i][j][lf][1] > curd + d[1][i][j] )
            {
                dist[i][j][lf][1] = curd + d[1][i][j];
                nodes[ (dist[i][j][lf][1]) ].push( {i,j,lf,1} );
                cnt++;
            }
            for(int k = 0; k < 4; k++)
            {
                int x = i + xi[k], y = j + yi[k];
                if(!inside(x,y)) continue;
                int w = abs( a[x][y] - p );
                if(dist[x][y][lf][rt] > curd + w )
                {
                    dist[x][y][lf][rt] = curd + w;
                    nodes[ (curd + w) ].push( {x,y, lf, rt} );
                    cnt++;
                }
            }
        }
    }
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> c;
            a[i][j] = int(c) - 48;
        }
    }
    int res = INF;
    for(int p = 0; p <= 9; p++)
    {
        preCalc(0,p);
        preCalc(1,p);
        calcDist(p);
        for(int j = 1; j <= m; j++)
        {
            res = min(res, dist[n][j][1][1]);
        }
    }
    cout << res;
}
