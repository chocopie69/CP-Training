#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 3e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,k, a[SZ][SZ], b[SZ][SZ], sum[SZ][SZ];

int getSum(int i, int j, int u, int v)
{
    return sum[u][v] - sum[u][j-1] - sum[i-1][v] + sum[i-1][j-1];
}

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            b[i - j + n][i + j] = a[i][j];
        }
    }
    for(int i = 1; i <= 2*n; i++)
    {
        for(int j = 1; j <= 2*n; j++)
        {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + b[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int u = i - j + n, v = i + j;
            cout << getSum(max(u-k,1), max(v-k,1), min(u+k,2*n), min(v+k,2*n)) << " ";
        }
        cout << '\n';
    }
}

