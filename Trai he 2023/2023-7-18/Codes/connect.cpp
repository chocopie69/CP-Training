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

const int SZ = 500+50;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;
const int LIM = 10;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Edge
{
    int i, j, w;
    Edge(int _i = 0, int _j = 0, int _w = 0)
    {
        i = _i;
        j = _j;
        w = _w;
    }
};

int n,m,q, xi[4] = {1,0,-1,0}, yi[4] = {0,1,0,-1}, a[SZ][SZ], d[SZ][SZ][3];
char c;
queue<pii> qu[10];
bool vis[SZ][SZ];
vector<Edge> adj[SZ][SZ];

bool inside(int i, int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

void createGraph(int s)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                int x = i + xi[k], y = j + yi[k];
                if(!inside(x,y)) continue;
                adj[i][j].push_back({x,y,abs(a[x][y] - s)})
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        adj[n+1][n+1].push_back({i,1, abs(a[i][1] - s) })
        adj[n+3][n+3].push_back({ i,m, abs(a[i][m] - s) });
    }
    for(int j = 1; j <= m; j++)
    {
        adj[n+2][n+2].push_back({ 1,j, abs(a[1][j] - s) });
        adj[n][j].push_back({ n+4, n+4, 0 });
    }
}

void dial(int sx, int sy,int dir)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            d[i][j][dir] = INF;
        }
    }
    for(int i = 0; i <= LIM; i++)
    {
        while(!qu[i].empty()) qu[i].pop();
    }
    d[sx][sy][dir] = 0;
    qu[0].push({sx,sy});
    memset(vis,false,sizeof(vis));
    int cnt = 1, pos = 0;
    while(cnt > 0)
    {
        while(qu[pos].empty())
        {
            pos++;
            if(pos >= LIM) pos = 0;
        }
        pii u = qu[pos].front();
        qu[pos].pop();
        cnt--;
        int i = u.fi, j = u.se;
        if(vis[i][j]) continue;
        vis[i][j] = true;
        for(int k = 0; k < 4; k++)
        {
            int x = i + xi[k], y = j + yi[k];
            if(!inside(x,y) || vis[x][y]) continue;
            int w;
            if(a[i][j] == k) w = 1;
            else if(abs(k-a[i][j]) == 2) w = 3;
            else w = 2;
            //cout << i << " " << j << " - " << x << " " << y << " - " << w << '\n';
            if(d[x][y] > d[i][j] + w)
            {
                d[x][y] = d[i][j] + w;
                qu[ d[x][y] % LIM ].push({x,y});
                cnt++;
            }
        }
    }
    cout << d[tx][ty] << '\n';
}

int main()
{
    init();
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> c;
            a[i][j] = int(c) - 48;
        }
    }
    for(int p = 0; p <= 9; p++)
    {
        createGraph(p);
    }
}

