#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "BONUS"

using namespace std;

const int LIMIT = 1e7;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll m,n,q,x,y,u,v,a2[LIMIT],sum2[LIMIT];

ll getA(int i,int j)
{
    if((i-1)*n + j < 0) return 0;
    return a2[(i-1)*n + j];
}

ll getSum(int i,int j)
{
    if((i-1)*n + j < 0) return 0;
    return sum2[(i-1)*n + j];
}

int main()
{
    init();
    cin >> m >> n >> q;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a2[(i-1)*n + j];
            sum2[(i-1)*n + j] = getSum(i-1,j) + getSum(i,j-1) - getSum(i-1,j-1) + getA(i,j);
        }
    }
    while(q--)
    {
        cin >> x >> y >> u >> v;
        cout << getSum(u,v) - getSum(x-1,v) - getSum(u,y-1) + getSum(x-1,y-1) << '\n';
    }
    //cout << getSum(0,1);
}

/*
4 2 1
2 2
3 0
0 1
4 6
*/
