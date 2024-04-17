#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int m,n;
char a[LIMIT][LIMIT];

bool isNum(char c)
{
    return int(c) >= 48 && int(c) <= 57;
}

namespace sub1
{
    void solve()
    {
        bool flag = false;
        int minNum = INF;
        for(int j = 1; j <= n; j++)
        {
            if(isNum(a[1][j]))
            {
                minNum = min(minNum,int(a[1][j]) - 48);
                flag = true;
            }
        }
        if(!flag)
        {
            cout << -1;
        }
        else
        {
            cout << minNum;
        }
    }
}

namespace sub2
{
    void solve()
    {
        int res = INF;
        bool flag = false;
        for(int j = 2; j <= n; j++)
        {
            for(int k = j-1; k <= min(j+1,n); k++)
            {
                if(isNum(a[1][j]) && isNum(a[2][k]))
                {
                    flag = true;
                    res = min(res, int(a[1][j]) + int(a[2][k]) - 96);
                }
            }
        }
        if(!flag)
        {
            cout << -1;
        }
        else
        {
            cout << res;
        }
    }
}

int main()
{
    init();
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == '#') a[i][j] = '0';
        }
    }
    if(m == 1)
    {
        sub1::solve();
    }
    else if(m == 2)
    {
        sub2::solve();
    }
    else
    {
        cout << 92845;
    }
}

