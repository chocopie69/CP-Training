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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, res = 1;
pll a[SZ];
ll b[SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++)
    {
        b[i] = INFLL;
    }
    b[0] = -INFLL;
    for(int i = 1; i <= n; i++)
    {
        int pos = upper_bound(b+1, b+n+1, a[i].fi - a[i].se) - b;
        b[pos] = min(b[pos],a[i].fi + a[i].se);
        res = max(res,pos);
    }
    cout << res;
}
