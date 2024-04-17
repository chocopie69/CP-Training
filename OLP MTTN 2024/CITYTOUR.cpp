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

const int SZ = 3e6+5, OFFSET = 1e6+1;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

ll n,k, a[SZ], sum[SZ], mx[SZ];

namespace sub1
{
    void solve()
    {
        ll res = 0;
        for(int i = 1; i <= n; i++)
        {
            sum[i - a[i] + OFFSET] += a[i];
            res = max(res, sum[i - a[i] + OFFSET]);
        }
        cout << res;
    }
}

namespace sub2
{
    void solve()
    {
        ll res = 0, cur = 0;
        mx[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            sum[i - a[i] + OFFSET] += a[i];
            mx[i] = max(mx[i-1], sum[i - a[i] + OFFSET]);
        }
        for(int i = 1; i <= n; i++)
        {
            sum[i - a[i] + OFFSET] -= a[i];
        }
        for(int i = n; i >= 1; i--)
        {
            sum[i - a[i] + OFFSET] += a[i];
            cur = max(cur, sum[i - a[i] + OFFSET]);
            res = max(res, cur + mx[i-1]);
        }
        cout << res;
    }
}

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(k == 0) sub1::solve();
    else if(k == 1) sub2::solve();
}

/*
9 1
3 4 5 6 6 6 100 8 9
*/

