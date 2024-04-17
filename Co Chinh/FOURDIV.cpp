#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define int long long

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 4e6+10;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t,d;
bool prime[LIMIT];
vector<int> primes;

void sieve()
{
    memset(prime,true,sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i * i < LIMIT;i++)
    {
        if(prime[i]) for(int j = i*i; j < LIMIT; j += i)
        {
            prime[j] = false;
        }
    }
    for(int i = 2; i < LIMIT; i++)
    {
        if(prime[i]) primes.push_back(i);
    }
}

signed main()
{
    init();
    sieve();
    int t;
    cin >> t;
    while(t--)
    {
        cin >> d;
        int uoc1 = lower_bound(primes.begin(),primes.end(),d+1) - primes.begin();
        int uoc2 = lower_bound(primes.begin(),primes.end(),primes[uoc1]+d) - primes.begin();
        cout << primes[uoc1] * primes[uoc2] << '\n';
    }
}

