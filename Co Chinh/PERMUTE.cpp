#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "PERMUTE"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 123456789, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

ll n, a[SZ], b[SZ], p[SZ], mx[SZ];

bool inCycle[SZ];

ll minPrime[SZ];
vector<int> primes;

void sieve()
{
    for(int i = 2; i * i < SZ; i++)
    {
        if(minPrime[i] == 0) for(int j = i*i; j < SZ; j += i) minPrime[j] = i;
    }
    for(int i = 2; i < SZ; i++)
    {
        if(minPrime[i] == 0) minPrime[i] = i;
    }
}

void phantich(ll x)
{
    while(x > 1)
    {
        ll cur = minPrime[x], cnt = 0;
        while(cur == minPrime[x])
        {
            x /= cur;
            cnt++;
        }
        mx[cur] = max(mx[cur], cnt);
    }
}

ll mul(ll x, ll y)
{
    if(y == 0) return 1LL;
    ll cur = mul(x, y/2);
    cur = (cur * cur) % MOD;
    if(y % 2 == 1) cur = (cur * x) % MOD;
    return cur;
}

int main()
{
    init();
    cin >> n;
    sieve();
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
        a[i] = i;
        b[i] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        if(inCycle[i]) continue;
        ll cnt = 0;
        int pos = i;
        while(!inCycle[pos])
        {
            cnt++;
            inCycle[pos] = true;
            pos = p[pos];
        }
        phantich(cnt);
    }
    ll res = 1;
    for(ll i = 2; i < SZ; i++)
    {
        if(mx[i] > 0) res *= mul(i,mx[i]);
    }
//    for(int i = 1; i <= n; i++)
//    {
//        cout << cycle[i] << " ";
//    }
//    ll res = cycle[1];
//    for(int i = 2; i <= n; i++)
//    {
//        res = res*cycle[i] / __gcd(res, cycle[i]);
//    }
    cout << res;
}
