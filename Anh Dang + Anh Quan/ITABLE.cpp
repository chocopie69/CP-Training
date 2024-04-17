#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "ITABLE"

using namespace std;

const int SZ = 5e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,t,q, b[SZ][SZ], c[SZ][SZ], a[SZ][SZ];

int main()
{
    init();
    cin >> n >> t;
    while(t--)
    {
        ll k,rc,u,v;
        cin >> k >> rc >> u >> v;
        if(k == 1)
        {
            int cur = 1;
            for(int i = u; i <= (u+v)/2; i++)
            {
                a[rc][i] += cur;
                a[rc][v + 1 - cur] += cur;
                cur++;
            }
            if( (v - u + 1) % 2 == 1 )
            {
                int mid = (u + v) / 2;
                a[rc][mid] -= (mid - u + 1);
            }
        } else
        {
            int cur = 1;
            for(int i = u; i <= (u+v)/2; i++)
            {
                a[i][rc] += cur;
                a[v + 1 - cur][rc] += cur;
                cur++;
            }
            if( (v - u + 1) % 2 == 1 )
            {
                int mid = (u + v) / 2;
                a[mid][rc] -= (mid - u + 1);
            }
        }
    }
    cin >> q;
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        cout << a[x][y] << '\n';
    }
}
