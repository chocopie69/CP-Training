#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

int n,a[LIMIT][LIMIT], sum = 0, sum1 = 0;
string dx = "YES";

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] != a[j][i])
            {
                dx = "NO";
            }
        }
    }

    cout << dx << '\n';
    if(dx == "YES")
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cout << (i < j ? a[j][i] : a[i][j]) << " ";
            }
            cout << '\n';
        }
    }
}


