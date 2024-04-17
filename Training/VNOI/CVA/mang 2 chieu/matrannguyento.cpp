#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

int m,n,a[LIMIT][LIMIT], res = -1;
string found = "NO";

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool isPrime(int x)
{
    if(x < 2)
        return false;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    init();
    cin >> m >> n;
    for(int i = 1 ; i <= m; i++)
    {
        bool check = true;
        a[i][0] = -INT_MAX;
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j-1] >= a[i][j])
                check = false;
            if(isPrime(a[i][j]))
                res = max(res, a[i][j]);
        }
        if(check)
            found = "YES";
    }
    cout << found << '\n' << res;
}


