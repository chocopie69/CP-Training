#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "TPRIME"

using namespace std;

const int SZ = 2e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isPrime[SZ];
vector<ll> primes;

void sieve()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i < SZ; i++)
    {
        if(isPrime[i]) for(int j = i*i; j < SZ; j += i) isPrime[j] = false;
    }
    for(int i = 2; i < SZ; i++)
    {
        if(isPrime[i]) primes.push_back(1LL*i);
    }
}

ll n,k,a[SZ],sum[SZ], res = INFLL;

ll get(ll x)
{
    if(x <= 2) return 2-x;
    int pos1 = lower_bound(all(primes),x) - primes.begin();
    return min( abs(x-primes[pos1]),abs(x-primes[pos1-1]) );
}

int main()
{
    init();
    sieve();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + get(a[i]);
        //cout << get(a[i]) << " ";
        if(i >= k)
        {
            res = min(res,sum[i] - sum[i-k]);
        }
    }
    cout << res;
}


