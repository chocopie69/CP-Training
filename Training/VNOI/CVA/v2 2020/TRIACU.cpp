#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "TRIACU"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n;
pll a[SZ];
ll sum[SZ], res = 0;

ll minhvungu(ll x)
{
    int lo = 1, hi = n, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(a[mid].fi >= x)
        {
            hi = mid-1;
        } else
        {
            lo = mid+1;
        }
    }
    return lo-1;
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        a[i].fi *= a[i].fi;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i].se;
    }
    for(int i = 1; i <= n-2; i++)
    {
        for(int j = i+1; j <= n-1; j++)
        {
            ll x = a[i].fi + a[j].fi;
            int pos;
            if(x > a[n].fi) pos = n;
            else pos = minhvungu(x);
            if(pos > j) res += 1LL*a[i].se*a[j].se*(sum[pos] - sum[j]);
        }
    }
    cout << res;
}
