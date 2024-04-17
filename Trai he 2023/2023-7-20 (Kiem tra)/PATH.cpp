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

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;
const int LIM = 4;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,q, xi[4] = {1,0,-1,0}, yi[4] = {0,1,0,-1}, a[SZ][SZ], sx, sy, tx, ty, d[SZ][SZ];
char c;
queue<pii> qu[5];
bool vis[SZ][SZ];

bool inside(int i, int j)
{
    return i >= 1 && i <= n && j >= 1 && j <= m;
}

void dial()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            d[i][j] = INF;
        }
    }
    for(int i = 0; i <= LIM; i++)
    {
        while(!qu[i].empty()) qu[i].pop();
    }
    d[sx][sy] = 0;
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
            if(c == 'N') a[i][j] = 2;
            else if(c == 'E') a[i][j] = 1;
            else if(c == 'S') a[i][j] = 0;
            else a[i][j] = 3;
        }
    }
    while(q--)
    {
        cin >> sx >> sy >> tx >> ty;
        dial();
    }
}
