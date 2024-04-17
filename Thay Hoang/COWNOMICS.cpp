#include <bits/stdc++.h>
#define ll unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "COWNOMICS"

using namespace std;

const int LIMIT = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,res = 0, cur1, cur2;
char c[LIMIT][LIMIT];
string s;

ll getNum(char c)
{
    if(c == 'A') return 0;
    else if(c == 'C') return 1;
    else if(c == 'G') return 2;
    return 3;
}

ll getCode(int i, int j, int k,int h)
{
    ll res = 0;
    res = (ll) 16*getNum(c[h][i]) + 4*getNum(c[h][j]) + getNum(c[h][k]);
    return (ll)1 << res;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n*2; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
        }
    }
    for(int i = 1; i <= m-2; i++)
    {
        for(int j = i+1; j <= m-1; j++)
        {
            for(int k = j+1; k <= m; k++)
            {
                cur1 = 0, cur2 = 0;
                for(int h = 1;h <= n;h++)
                {
                    cur1 |= getCode(i,j,k,h);
                }
                for(int h = n+1;h <= 2*n;h++)
                {
                    cur2 |= getCode(i,j,k,h);
                }
                if((cur1 & cur2) == 0) res++;
            }
        }
    }
    cout << res;
}


