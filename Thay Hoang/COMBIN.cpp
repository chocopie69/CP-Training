#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "COMBIN"

using namespace std;

const int LIMIT = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,k,m,c[LIMIT][LIMIT];

void preCompute()
{
    memset(c,0,sizeof(c));
    for(int i = 0; i <= n; i++)
    {
        c[i][0] = 1;
        c[i][i] = 1;
        for(int j = 1; j < i; j++)
        {
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
}

int main()
{
    init();
    cin >> n >> k >> m;
    m++;
    k--;
    preCompute();
    int prev = n-1;
    while(k >= 0)
    {
        int cur = 0;
        while(cur + c[prev][k] <= m && prev >= 0)
        {
            cur += c[prev][k];
            prev--;
        }
        m -= cur;
        cout << prev << " " << k << '\n';
    }
}

