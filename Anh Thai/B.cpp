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

int n, pos[SZ];
ll m,p, a[SZ], sum = 0, res = 0;
pll b[SZ];

int lwb(ll x)
{
    int lo = 1, hi = n, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(b[mid].fi >= x)
        {
            hi = mid-1;
        } else
        {
            lo = mid+1;
        }
    }
    return lo;
}

struct Fenwick
{
    int nodes[SZ];

    void update(int pos)
    {
        while(pos <= n)
        {
            nodes[pos]++;
            pos += pos & (-pos);
        }
    }

    int query(int pos)
    {
        int s = 0;
        while(pos > 0)
        {
            s += nodes[pos];
            pos -= pos & (-pos);
        }
        return s;
    }
} ft;

int main()
{
    init();
    cin >> n >> m >> p;
    sum = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        b[i] = {sum, i};
    }
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++)
    {
        pos[b[i].se] = i;
    }
    sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += a[i];
        if(sum >= m && sum <= p) res++;
        int lo = lwb(sum - p), hi = lwb(sum - m + 1) - 1;
        if(lo <= hi)
        {
            res += 1LL*ft.query(hi) - ft.query(lo - 1);
        }
        ft.update(pos[i]);
    }
    cout << res;
}

