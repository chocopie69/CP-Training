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

int n,q, a[SZ][SZ];

struct FenwickTree
{
    int nodes[SZ][SZ];

    void update(int x, int y, int val)
    {
        for(int u = x ; u <= n; u += u & (-u) )
        {
            for(int v = y ; v <= n; v += v & (-v))
            {
                nodes[u][v] += val;
            }
        }
    }

    int query(int x, int y)
    {
        int sum = 0;
        for(int u = x ; u > 0; u -= u & (-u) )
        {
            for(int v = y ; v > 0; v -= v & (-v))
            {
                sum += nodes[u][v];
            }
        }
        return sum;
    }
} ft;

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = (c == '*' ? 1 : 0);
            ft.update(i,j,a[i][j]);
        }
    }
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int x,y;
            cin >> x >> y;
            ft.update(x, y, (a[x][y] == 1 ? -1 : 1));
            a[x][y] = 1 - a[x][y];
        } else
        {
            int x,y,u,v;
            cin >> x >> y >> u >> v;
            cout << ft.query(u,v) - ft.query(x-1,v) - ft.query(u, y-1) + ft.query(x-1, y-1) << '\n';
        }
    }
}

