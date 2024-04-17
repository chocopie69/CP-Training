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

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m, a[SZ][SZ], xi[8] = {1,0,-1,0, 1, 1, -1, -1}, yi[8] = {0,1,0,-1, 1, -1, 1, -1};
bool vis[SZ][SZ];

int main()
{
    init();
//    for(int i = 0; i < 8; i++)
//    {
//        cout << xi[i] << ' ' << yi[i] << " " << i << '\n';
//    }
//    return 0;
    while(cin >> n)
    {
        if(n == -1) break;
        cin >> m;
        ll red = 0;
        memset(vis,false,sizeof(vis));
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                char c;
                cin >> c;
                if(c == '*')
                {
                    a[i][j] = 1;
                    red++;
                }
                else a[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                bool flag = false;
                for(int k = 0; k < 4; k++)
                {
                    int x = i + xi[k], y = j + yi[k];
                    if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 1) flag = true;
                }
                if(!flag) for(int k = 0; k < 4; k++)
                {
                    int x = i + xi[k], y = j + yi[k];
                    vis[x][y] = true;
                }
                flag = false;
                for(int k = 4; k < 8; k++)
                {
                    int x = i + xi[k], y = j + yi[k];
                    if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 1) flag = true;
                }
                if(!flag && a[i][j] == 1 )
                {
                    for(int k = 4; k < 8; k++)
                    {
                        int x = i + xi[k], y = j + yi[k];
                        vis[x][y] = true;
                    }
                    vis[i][j] = true;
                }
            }
        }
        ll dem = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(vis[i][j]) dem++;
            }
        }
        cout << (dem == red ? "YES" : "NO") << '\n';
    }
}
