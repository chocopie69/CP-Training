#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NAME"

using namespace std;

const int SZ = 500+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m;
char a[SZ][SZ];
string res = "NO";

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n-1; i++)
    {
        for(int j = 1; j <= m-1; j++)
        {
            if(a[i][j] != a[i+1][j] && a[i][j] != a[i][j+1] && a[i+1][j] != a[i+1][j+1] && a[i+1][j+1] == a[i][j+1]) res = "YES";
        }
    }
    cout << res;
}

