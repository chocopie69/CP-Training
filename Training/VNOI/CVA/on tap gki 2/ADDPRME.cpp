#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 5005;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,dp[LIMIT], pos = 0;
vector<ll> primes;
bool isPrime[LIMIT];

void sieve(int n)
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= n; i++)
    {
        if(isPrime[i]) for(int j = i*i; j <= n; j+=i)
        {
            isPrime[j] = false;
        }
    }
    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i]) primes.push_back(i);
    }
}

int main()
{
    init();
    cin >> n;
    sieve(LIMIT-1);
    dp[0] = 1;
    for(ll prime : primes)
    {
        for(int i = 1; i <= n; i++)
        {
            if(i >= prime) dp[i] += dp[i-prime];
        }
    }
    cout << dp[n];
}

