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

ll a,b,k;

namespace sub3
{
    ll res = 0, x, m, n, fact[SZ];

    void calc()
    {
        fact[0] = 1;
        for(int i = 1; i < SZ; i++)
        {
            fact[i] = (fact[i-1] * i) % MOD;
        }
    }

    ll power(ll a, ll b)
    {
        if(b == 0) return 1LL;
        ll cur = power(a, b/2);
        if(b % 2 == 0) return (cur * cur) % MOD;
        return ((cur * cur) % MOD * (a % MOD)) % MOD;
    }

    ll ckn(ll k, ll n)
    {
        if(k > n) return 0;
        ll cur = fact[k] * fact[n-k];
        cur %= MOD;
        return (fact[n] * power(cur, MOD-2)) % MOD;
    }

    void solve()
    {
        calc();
        for(int i = 0; i < 32; i++)
        {
            if(b >> i & 1) x = i;
        }
        for(int i = 0; i < 32; i++)
        {
            if((1LL << i) > a) break;
            int j = x-i;
            ll cur = ckn(k-1, i+k-1) * ckn(k-1, j+k-1);
            cur %= MOD;
            res = (res + cur) % MOD;
        }
        cout << res;
    }
}

int main()
{
    init();
    cin >> a >> b >> k;
    sub3::solve();
}

