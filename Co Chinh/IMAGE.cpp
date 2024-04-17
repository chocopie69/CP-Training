#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "IMAGE"

using namespace std;

const int SZ = 2e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,a[SZ][SZ], sum[SZ][SZ];

ll getSum(int i, int j, int u, int v)
{
    return sum[u][v] - sum[i-1][v] - sum[u][j-1] + sum[i-1][j-1];
}

ll recur(int s, int u, int v)
{
    int i = u - (1 << s) + 1;
    int j = v - (1 << s) + 1;
    if(getSum(i,j,u,v) == 0 || getSum(i,j,u,v) == (1 << (s*2))) return 2*1LL;
    ll sum = 0;
    return 1LL + recur(s-1, u - (1 << (s-1)), v - (1 << (s-1))) + recur(s-1, u, v - (1 << (s-1))) + recur(s-1,u,v) + recur(s-1,u - (1 << (s-1)),v);
}

int main()
{
    init();
    cin >> n;
    memset(sum,0,sizeof(sum));
    for(int i = 1; i <= (1 << n); i++)
    {
        for(int j = 1; j <= (1 << n); j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    cout << recur(n, (1 << n), (1 << n));
}

/*
3
1 1 1 1 1 1 0 1
1 1 0 1 0 0 1 1
0 1 0 0 1 0 1 0
0 0 1 1 0 1 0 1
1 1 1 1 1 1 0 1
1 1 0 1 0 0 1 1
0 1 0 0 1 0 1 0
0 0 1 1 0 1 0 1
*/
