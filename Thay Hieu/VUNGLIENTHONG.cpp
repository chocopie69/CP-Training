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

const int SZ = 1e3+5, SZ2 = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int m,n,q, a[SZ][SZ];
bool vis[SZ][SZ];

struct DSU
{
    pii par[SZ][SZ];
    int s[SZ][SZ];

    void init(int n, int m)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                par[i][j] = {i,j};
                s[i][j] = 1;
            }
        }
    }

    pii get(pii u)
    {
        return (par[u.fi][u.se] == u ? u : par[u.fi][u.se] = get(par[u.fi][u.se]));
    }

    void join(pii u, pii v)
    {
        u = get(u);
        v = get(v);
        if(u == v) return;
        if(s[u.fi][u.se] < s[v.fi][v.se]) swap(u,v);
        par[v.fi][v.se] = u;
        s[u.fi][u.se] += s[v.fi][v.se];
    }

    bool joined(pii u, pii v)
    {
        u = get(u);
        v = get(v);
        return u == v;
    }
} dsu;


int cnt = 0, xi[4] = {1, 0, -1, 0}, yi[4] = {0, 1, 0, -1}, idx = 0;

bool inside(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void dfs(int x, int y, int sx, int sy)
{
    vis[x][y] = true;
    //dsu.join({x,y}, {sx,sy});
    for(int i = 0; i < 4; i++)
    {
        int nx = x + xi[i], ny = y + yi[i];
        if(!inside(nx,ny) || vis[nx][ny] || a[nx][ny] != 0) continue;
        dsu.join({x,y}, {nx,ny});
        dfs(nx, ny, sx, sy);
    }
}

int xa[SZ2], xb[SZ2], ya[SZ2], yb[SZ2];
stack<int> st;

int main()
{
    init();
    cin >> n >> m >> q;
    swap(n,m);
    for(int i = 1; i <= q; i++)
    {
        cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
        swap(xa[i], ya[i]);
        swap(xb[i], yb[i]);
        if(xa[i] == xb[i])
        {
            for(int y = ya[i]; y <= yb[i]; y++)
            {
                a[xa[i]][y]++;
                //cout << xa[i] << " " << y << '\n';
            }
        } else
        {
            for(int x = xa[i]; x <= xb[i]; x++)
            {
                a[x][ya[i]]++;
                //cout << x << " " << ya[i] << '\n';
            }
        }
    }
    dsu.init(n,m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(!vis[i][j] && a[i][j] == 0)
            {
                cnt++;
                dfs(i,j,i,j);
                //cout << i << " " << j << '\n';
            }
        }
    }
    for(int k = q; k >= 1; k--)
    {
        st.push(cnt);
        if(xa[k] == xb[k])
        {
            int x = xa[k];
            //for(int y = ya[k]; y <= yb[k]; y)
            for(int y = ya[k]; y <= yb[k]; y++)
            {
                a[x][y]--;
                if(a[x][y] == 0) cnt++;
            }
            for(int y = ya[k]; y <= yb[k]; y++)
            {
                if(a[x][y] == 0)
                {
                    for(int i = 0; i < 4; i++)
                    {
                        int nx = x + xi[i], ny = y + yi[i];
                        if(inside(nx,ny) && !dsu.joined( {x,y}, {nx,ny} ) && a[nx][ny] == 0)
                        {
                            dsu.join({x,y}, {nx,ny});
                            cnt--;
                        }
                    }
                }
            }
        } else
        {
            int y = ya[k];
            for(int x = xa[k]; x <= xb[k]; x++)
            {
                a[x][y]--;
                if(a[x][y] == 0) cnt++;
            }
            for(int x = xa[k]; x <= xb[k]; x++)
            {
                if(a[x][y] == 0)
                {
                    for(int i = 0; i < 4; i++)
                    {
                        int nx = x + xi[i], ny = y + yi[i];
                        if(inside(nx,ny) && !dsu.joined( {x,y}, {nx,ny} ) && a[nx][ny] == 0)
                        {
                            dsu.join({x,y}, {nx,ny});
                            cnt--;
                        }
                    }
                }
            }
        }
    }
    while(!st.empty())
    {
        cout << st.top() << '\n';
        st.pop();
    }
}
