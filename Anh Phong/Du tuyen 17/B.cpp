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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n, m;
pii a[SZ];
ll res = 0;

struct Fenwick
{
    int nodes[SZ];

    void update(int pos, int val)
    {
        //cout << "update " << pos << " " << val << '\n';
        while(pos <= m)
        {
            nodes[pos] += val;
            pos += pos & (-pos);

        }
    }

    int query(int pos)
    {
        int sum = 0;
        while(pos > 0)
        {
            sum += nodes[pos];
            pos -= pos & (-pos);
        }
        return sum;
    }
} ft;

int main()
{
    init();
    cin >> n;
    m = 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        m = max(m, a[i].fi + 1);
    }
    sort(a + 1, a + n + 1);
    int h = 1;
    for(int i = 1; i <= n; i++)
    {
        if(h > a[i].fi) h = 1;
        if(a[i].fi - h + 1 >= a[i].se)
        {
            ft.update(h, 1);
            h += a[i].se;
            ft.update(h, -1);
            //res += 1LL*x*a[i].se;
        } else
        {
            ft.update(h, 1);
            int cur = a[i].fi - h + 1;
            ft.update(h + cur, -1);
            //res += 1LL*x*cur;
            h = 1;
            ft.update(h, 1);
            //x++;
            int y = a[i].se - cur;
            //res += 1LL*x*y;
            h += y;
            ft.update(h, -1);
        }
    }
    for(int i = 1; i < m; i++)
    {
        int x = ft.query(i);
        if(x < 1) continue;
        //cout << i << " " << x << '\n';
        res += 1LL*x*(x-1)/2;
    }
    cout << res;
}
