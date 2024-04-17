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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,q,x,y,u,v;

int main()
{
    init();
    cin >> n >> m >> q;
    while(q--)
    {
        int res = 0;
        cin >> x >> y >> u >> v;
        for(int j = y; j <= v; j++)
        {
            //cout << x << " " << j << " " << (x & j) << '\n';
            if( (x & j) == 0)
            {
                if(j == y || (x & (j-1) ) > 0)
                {
                    res++;
                    //cout << x << " " << j << '\n';
                }
            }
        }
        for(int i = x; i <= u; i++)
        {
            //cout << i << " " << y << " " << (i & y) << '\n';
            if(i == x && (i & y) == 0) continue;
            if( (i & y) == 0)
            {
                if(i == x || ((i-1) & y ) > 0)
                {
                    res++;
                    //cout << i << " " << y << '\n';
                }
            }
        }
        cout << res << '\n';
    }
}

/*
3 5 1
0 0 1 1
*/
