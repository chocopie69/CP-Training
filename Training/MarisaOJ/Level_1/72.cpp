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
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m,q, a[SZ][SZ];

int main()
{
    init();
    cin >> n >> m >> q;
    while(q--)
    {
        int i,j,u,v;
        cin >> i >> j >> u >> v;
        a[i][j]++;
        a[u+1][v+1]++;
        a[u+1][j]--;
        a[i][v+1]--;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}

