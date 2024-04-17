#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "INCREASING"

using namespace std;

const int SZ = 3e5+5, LG = 25;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin);
    freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,h,a[SZ],b[SZ],sum[SZ], res = INFLL, st[30][SZ], lg[SZ], lo, hi;

void rmq()
{
    for (ll i = 1; i <= n; ++i) st[0][i] = a[i];
    for (ll j = 1; (1 << j) <= n; ++j)
        for (ll i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}

ll getMax(ll l, ll r)
{
    ll k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}

int main()
{
    init();
    cin >> n >> h;
    sum[0] = 0;
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] -= (i-1);
        sum[i] = sum[i-1] + a[i];
    }
    rmq();
    for(ll i = 1; i + h - 1 <= n; i++)
    {
        if(getMax(i,i + h - 1) <= 1 - (i - 1))
        {
            res = min(res,(1-(i-1))*h - (sum[i+h-1] - sum[i-1]) );
        }
    }
    cout << (res == INFLL ? -1 : res);
}

