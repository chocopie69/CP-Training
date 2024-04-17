#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "PARTITION"

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

ll n, a[SZ], sum[SZ], s = 0, res = INFLL, mx = -INFLL, d = 1LL;
set<ll> nums;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    s = sum[n];
    if(s < 0)
    {
        s = -s;
        for(int i = 1; i <= n; i++)
        {
            a[i] = -a[i];
            sum[i] = sum[i-1] + a[i];
        }
        d = -1LL;
    }
    for(int i = 1; i <= n; i++)
    {
        mx = max(mx, a[i]);
    }
    //cout << s << '\n';
    if(s == 0)
    {
        cout << 0;
        return 0;
    }
    //cout << found(9) << '\n';
    for(ll k = n; k >= 1; k--)
    {
        bool found = true;
        if(s % k != 0) continue;
        ll x = s/k, cur = 0;
        for(ll i = 1; i <= n; i++)
        {
            cur += a[i];
            if(cur == x) cur = 0;
            else if(cur > x || i == n)
            {
                found = false;
                break;
            }
        }
        if(found)
        {
            cout << x*d;
            return 0;
        }
    }
}

/*
6
1 -2 0 -1 2 -3
-1 2 0 1 -2 3
*/
