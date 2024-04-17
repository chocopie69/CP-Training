#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "SET"

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

int t;
ll k,a,b,m,p,q;
bool vis[SZ][SZ];
queue<pll> qu;

void bfs(ll x, ll y)
{
    memset(vis,false,sizeof(vis));
    qu.push({x,y});
    while(!qu.empty())
    {
        ll curX = qu.front().fi, curY = qu.front().se;
        //cout << curX << " " << curY << '\n';
        qu.pop();
        if(curX > 500 || curY > 500) continue;
        if(vis[curX+1][curY+1] == false)
        {
            qu.push({curX+1,curY+1});
            vis[curX+1][curY+1] = true;
        }
        if(curX % k == 0 && curY % k == 0 && vis[curX/k][curY/k] == false)
        {
            qu.push({curX/k,curY/k});
            vis[curX/k][curY/k] = true;
        }
        for(int i = 0; i <= 500; i++)
        {
            if(vis[curY][i] && !vis[curX][i])
            {
                qu.push({curX,i});
                vis[curX][i] = true;
            }
        }
    }
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> k >> a >> b >> m;
        bfs(a,b);
        while(m--)
        {
            cin >> p >> q;
            if(vis[p][q])
            {
                cout << "YES" << '\n';
            } else
            {
                cout << "NO" << '\n';
            }
        }
    }
}
