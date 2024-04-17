#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e3+5;
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
ull res, black, white;
char c[SZ][SZ];

int id(char c)
{
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    return 3;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= 2*n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
        }
    }
    for(int j = 1; j <= m; j++)
    {
        black = 0;
        white = 0;
        for(int i = 1; i <= n; i++)
        {
            black |= (1LL << id(c[i][j]));
        }
        for(int i = n+1; i <= 2*n; i++)
        {
            white |= (1LL << id(c[i][j]));
        }
        if((black & white) == 0) res++;
    }
    cout << res;
}
