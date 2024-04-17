#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "tichnt"

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
    primes.push_back(666);
    for(int i = 2; i < SZ; i++)
    {
        if(isPrime[i]) primes.push_back(1LL*i);
    }
}

ll x,k,n, res = -1;

int main()
{
    init();
    cin >> x >> k;
    sieve();
    n = primes.size()-1;
    ll cur = 1;
    for(int i = 1; i <= k; i++)
    {
        cur *= primes[i];
    }
    int i = 1;
    while(cur <= x)
    {
        //cout << cur << '\n';
        res = max(res,cur);
        cur /= primes[i];
        int j = i+k;
        if( (double) cur <= (double) x / primes[j])
        {
            cur *= primes[j];
        } else break;
        i++;
    }
    cout << res;
}
