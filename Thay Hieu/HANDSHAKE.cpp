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

int n,m, a[SZ][SZ], xi[8] = {1,0,-1, 0, 1, 1, -1, -1}, yi[8] = {0, 1, 0, -1, 1, -1, 1, -1};
char c;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> c;
            if(c == 'o') a[i][j] = 1;
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == 0) continue;
            int cnt = 0;
            for(int k = 0; k < 8; k++)
            {
                int x = i + xi[k], y = j + yi[k];
                if(a[x][y] == 1) res++;
            }
        }
    }
    res /= 2;
    int mx = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == 1) continue;
            int cnt = 0;
            for(int k = 0; k < 8; k++)
            {
                int x = i + xi[k], y = j + yi[k];
                if(a[x][y] == 1) cnt++;
            }
            mx = max(mx, cnt);
        }
    }
    cout << res + mx;
}
