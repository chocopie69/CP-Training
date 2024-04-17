#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "UDTBOARD"

using namespace std;

const int SZ = 500+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int m,n,q, u1, v1, u2, v2, a[SZ][SZ], d[SZ][SZ];

int main()
{
    init();
    cin >> n >> m >> q;
    while(q--)
    {
        cin >> u1 >> v1 >> u2 >> v2;
        for(int i = u1; i <= u2; i++)
        {
            d[i][v1]++;
            d[i][v2+1]--;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int s = 0;
        for(int j = 1; j <= m; j++)
        {
            s += d[i][j];
            a[i][j] = s;
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

/*
3 4 2
1 1 2 3
2 2 3 4
*/
