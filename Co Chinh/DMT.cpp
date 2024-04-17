#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "DMT"

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

int t;
ll a,b, res;
bool isPrime[SZ];
vector<ll> primes;

void sieve()
{
    memset(isPrime,true,sizeof(isPrime));
    for(ll i = 2; i * i < SZ; i++)
    {
        if(isPrime[i]) for(ll j = i*i; j < SZ; j+=i)
        {
            isPrime[j] = false;
        }
    }
    for(ll i = 2; i < SZ; i++)
    {
        if(isPrime[i] && i != 3) primes.push_back(i);
    }
}

int main()
{
    init();
    cin >> t;
    sieve();
    //for(ll p : primes) cout << p << " ";
    while(t--)
    {
        cin >> a >> b;
        res = 0;
        if(6561 >= a && 6561 <= b) res++;
        int lo = 0, hi = primes.size()-1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(primes[mid]*primes[mid]*9LL >= a)
            {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        int L = lo;
        lo = 0, hi = primes.size()-1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(primes[mid]*primes[mid]*9LL > b)
            {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        int R = lo;
        res += R-L;
        cout << res << '\n';
    }
}

