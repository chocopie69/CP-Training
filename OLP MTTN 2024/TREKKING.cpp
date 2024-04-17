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

int n,q;
ll a[SZ], b[SZ], res[SZ], sum[SZ];
pll queries[SZ];

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        sum[i] = sum[i-1] + b[i];
    }
    for(int i = 1; i <= q; i++)
    {
        cin >> queries[i].fi;
        queries[i].se = i;
    }
    sort(queries + 1, queries + q + 1);
    int j = 1;
    ll cur = 0;
    for(int i = 1; i <= q; i++)
    {
        ll x = queries[i].fi, id = queries[i].se;
        x -= sum[j-1];
        while(j <= n && x >= a[j])
        {
            cur += a[j];
            x -= b[j];
            j++;
        }
        res[id] = cur;
    }
    for(int i = 1; i <= q; i++)
    {
        cout << res[i] << '\n';
    }
}

