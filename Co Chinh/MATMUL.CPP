#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "MATMUL"

using namespace std;

const int SZ = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,p, a[SZ][SZ], b[SZ][SZ], c[SZ][SZ];

int main()
{
    init();
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= p; j++)
        {
            cin >> b[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= p; j++)
        {
            for(int k = 1; k <= m; k++)
            {
                c[i][j] += (a[i][k] * b[k][j]);
            }
            cout << c[i][j] << " ";
        }
        cout << '\n';
    }
}
