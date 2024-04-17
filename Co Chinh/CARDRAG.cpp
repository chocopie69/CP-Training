#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CARDRAG"

using namespace std;

const int SZ = 2e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m;
pii nx[4][SZ][SZ] ; /// 0 : W, 1 : E, 2 : N, 3 : S
char c[SZ][SZ];

int id(char x)
{
    if(x == 'W') return 0;
    if(x == 'E') return 1;
    if(x == 'N') return 2;
    return 3;
}

void preCompute()
{
    for(int i = 1; i <= n; i++)
    {
        pii prev = {0,0};
        for(int j = 1; j <= m; j++)
        {
            if(c[i][j] == '.') continue;
            nx[0][i][j] = prev;
            prev = {i,j};
        }
        prev = {0,0};
        for(int j = m; j >= 1; j--)
        {
            if(c[i][j] == '.') continue;
            nx[1][i][j] = prev;
            prev = {i,j};
        }
    }
    for(int j = 1; j <= m; j++)
    {
        pii prev = {0,0};
        for(int i = 1; i <= n; i++)
        {
            if(c[i][j] == '.') continue;
            nx[2][i][j] = prev;
            prev = {i,j};
        }
        prev = {0,0};
        for(int i = n; i >= 1; i--)
        {
            if(c[i][j] == '.') continue;
            nx[3][i][j] = prev;
            prev = {i,j};
        }
    }
}

bool canMove(int i, int j)
{
    return i != 0 && ( nx[id(c[i][j])][i][j].fi == 0  );
}

bool vis[SZ][SZ];

queue<pii> qu;

int main()
{
    init();
    while(cin >> n)
    {
        cin >> m;
        if(n == 0) break;
        memset(vis,false,sizeof(vis));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> c[i][j];
            }
        }
        preCompute();
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(canMove(i,j) && c[i][j] != '.')
                {
                    qu.push({i,j});
                    res++;
                    vis[i][j] = true;
                }
            }
        }
        while(!qu.empty())
        {
            int x = qu.front().fi, y = qu.front().se;
            //cout << x << " " << y << '\n';
            qu.pop();
            pii lf = nx[0][x][y], rt = nx[1][x][y];
            nx[1][lf.fi][lf.se] = rt;
            nx[0][rt.fi][rt.se] = lf;
            if(!vis[lf.fi][lf.se] && canMove(lf.fi,lf.se))
            {
                qu.push({lf.fi,lf.se});
                vis[lf.fi][lf.se] = true;
                res++;
            }
            if(!vis[rt.fi][rt.se] && canMove(rt.fi,rt.se))
            {
                qu.push({rt.fi,rt.se});
                vis[rt.fi][rt.se] = true;
                res++;
            }
            pii up = nx[2][x][y], down = nx[3][x][y];
            nx[3][up.fi][up.se] = down;
            nx[2][down.fi][down.se] = up;
            if(!vis[up.fi][up.se] && canMove(up.fi,up.se))
            {
                qu.push({up.fi,up.se});
                vis[up.fi][up.se] = true;
                res++;
            }
            if(!vis[down.fi][down.se] && canMove(down.fi,down.se))
            {
                qu.push({down.fi,down.se});
                vis[down.fi][down.se] = true;
                res++;
            }
        }
        cout << res << '\n';
    }
}
