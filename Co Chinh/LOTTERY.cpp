#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "LOTTERY"

using namespace std;

const int SZ = 1e7+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,k,a[SZ], lo, hi, res = 0, L, R, d, cnt[SZ];
map<ll,ll> mp;
vector<pll> v;

void sieve(ll x, ll y)
{
    for(ll i = max(x, (L + x - 1) / x * x); i <= R; i += x)
    {
        cnt[i-L] += y;
    }
}

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    cin >> lo >> hi;
    if(hi <= 0)
    {
        lo = -lo;
        hi = -hi;
        swap(lo, hi);
    }
    if(lo <= 0)
    {
        L = 0;
        R = max(abs(lo), abs(hi));
        d = min(abs(lo), abs(hi));
    } else
    {
        L = lo;
        R = hi;
        d = lo;
    }
    for(pll p : mp)
    {
        sieve(p.fi,p.se);
    }
//    for(int i = 1; i <= n; i++)
//    {
//        sieve(a[i]);
//    }
    for(ll x = lo; x <= hi; x++)
    {
        if(cnt[abs(x) - L] == k)
        {
            res++;
            //cout << x << '\n';
        }
        //cout << cnt[abs(x) - d] << " " << x << '\n';
    }
    cout << res;
    //cout << " " << L << " " << R << '\n';
}

/*
5 2
3 5 6 7 2
-30 24
*/

