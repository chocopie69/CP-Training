#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

int n,a[LIMIT][LIMIT], sum = 0, sum1 = 0;

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
            if(a[i][j] == 1)
            {
                sum++;
                if(i == j)
                    sum1++;
            }
        }
    }
    cout << (sum == sum1) << '\n' << n*n - sum;
}

