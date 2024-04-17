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

const int SZ = 302+5;
const ll INF = INT_MAX / 2, MOD = 1e9+9, INFLL = 2e18, base = 2;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m, a[SZ][SZ], b[SZ][SZ];
ll suma[SZ][SZ], sumb[SZ][SZ], powBase[SZ*SZ];

void calc()
{
    powBase[0] = 1;
    for(int i = 1; i <= 300*300; i++)
    {
        powBase[i] = (powBase[i-1] * base) % MOD;
    }
}

int posx(int x)
{
    return n - x + 1;
}

int posy(int y)
{
    return m - y + 1;
}

int id(int x, int y)
{
    return m * (x - 1) + y - 1;
}

int main()
{
    init();
    cin >> n >> m;
    calc();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            int x = c - '0';
            a[i][j] = x;
            suma[i][j] = suma[i][j-1] + suma[i-1][j] - suma[i-1][j-1] + powBase[ id(i,j) ]*x;
            suma[i][j] = ((suma[i][j] % MOD) + MOD) % MOD;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            b[i][j] = a[posx(i)][posy(j)];
            sumb[i][j] = sumb[i][j-1] + sumb[i-1][j] - sumb[i-1][j-1] + powBase[ id(i,j) ]*b[i][j];
            sumb[i][j] = ((sumb[i][j] % MOD) + MOD) % MOD;
        }
    }
    for(int s = min(n,m); s >= 2; s--)
    {
        bool flag = false;
        for(int i = 1; i + s - 1 <= n; i++)
        {
            for(int j = 1; j + s - 1 <= m; j++)
            {
                int u = i + s - 1, v = j + s - 1;
                ll val1 = suma[u][v] - suma[i-1][v] - suma[u][j-1] + suma[i-1][j-1];
                val1 = ((val1 % MOD) + MOD) % MOD;
                int u2 = posx(u) + s - 1, v2 = posy(v) + s - 1;
                ll val2 = sumb[u2][v2] - sumb[posx(u)-1][v2] - sumb[u2][posy(v)-1] + sumb[posx(u)-1][posy(v)-1];
                val2 = ((val2 % MOD) + MOD) % MOD;
                int id1 = id(i,j), id2 = id(posx(u), posy(v));
                if( (id1 <= id2 && (val1 * powBase[id2 - id1]) % MOD == val2) || (id1 > id2 && (val2 * powBase[id1 - id2]) % MOD == val1) )
                {
                    flag = true;
                }
            }
        }
        if(flag)
        {
            cout << s;
            return 0;
        }
    }
    cout << -1;
}
