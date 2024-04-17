#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NEAREST"

using namespace std;

const int LIMIT = 2e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, res;
bool prime[LIMIT+10];
vector<int> primes;

void sieve()
{
    memset(prime,true,sizeof(prime));
    for(int i = 2; i * i <= LIMIT; i++)
    {
        if(prime[i]) for(int j = i*i; j <= LIMIT; j+=i) prime[j] = false;
    }
    for(int i = 2; i <= LIMIT; i++)
    {
        if(prime[i]) primes.push_back(i);
    }
}

int main()
{
    init();
    sieve();
    while(cin >> n)
    {
        //if(n == 0) break;
        if(n <= 2)
        {
            cout << 2;
            continue;
        }
        if(prime[n]) cout << n << '\n';
        else
        {
            int pos = upper_bound(primes.begin(),primes.end(),n) - primes.begin();
            cout << (abs(n-primes[pos-1]) <= abs(n-primes[pos]) ? primes[pos-1] : primes[pos]) << '\n';
        }
    }
}

