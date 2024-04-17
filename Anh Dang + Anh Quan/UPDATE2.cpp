#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "UPDATE2"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,q;
ll a[SZ], b[SZ], c[SZ];

struct Query
{
    ll lo, hi, x;
    Query(ll _lo = 0, ll _hi = 0, ll _x = 0)
    {
        lo = _lo;
        hi = _hi;
        x = _x;
    }
} queries[SZ];

int main()
{
    init();
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        ll lo,hi,x;
        cin >> lo >> hi >> x;
        queries[i] = {lo,hi,x};
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        c[x]++;
        c[y+1]--;
    }
    for(int i = 1; i <= m; i++)
    {
        c[i] += c[i-1];
        b[queries[i].lo ] += queries[i].x * c[i];
        b[queries[i].hi + 1 ] -= queries[i].x * c[i];
    }
    for(int i = 1; i <= n; i++)
    {
        b[i] += b[i-1];
        cout << a[i] + b[i] << " ";
    }
}
