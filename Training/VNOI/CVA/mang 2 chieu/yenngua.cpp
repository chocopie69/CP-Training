#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

int m,n,a[LIMIT][LIMIT], maxRow[LIMIT], minRow[LIMIT], maxColumn[LIMIT], minColumn[LIMIT];

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    init();
    cin >> m >> n;
    for(int i = 1 ; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1 ; i <= m; i++)
    {
        maxRow[i] = -INT_MAX;
        minRow[i] = INT_MAX;
        for(int j = 1; j <= n; j++)
        {
            maxRow[i] = max(maxRow[i], a[i][j]);
            minRow[i] = min(minRow[i], a[i][j]);
        }
    }
    for(int j = 1 ; j <= n; j++)
    {
        maxColumn[j] = -INT_MAX;
        minColumn[j] = INT_MAX;
        for(int i = 1; i <= m; i++)
        {
            maxColumn[j] = max(maxColumn[j], a[i][j]);
            minColumn[j] = min(minColumn[j], a[i][j]);
        }
    }
    for(int i = 1 ; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int x = a[i][j];
            if((maxRow[i] == x && minColumn[j] == x) || (minRow[i] == x && maxColumn[j] == x))
                cout << i << " " << j << '\n';
        }
    }
}



