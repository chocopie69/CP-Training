#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "HPRIME"

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

int n,h;
bool prime[LIMIT+10];
vector<int> primes, res;

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

int tcs(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

int main()
{
    init();
    sieve();
    cin >> n >> h;
    int i = 0;
    while(primes[i] <= n)
    {
        if(tcs(primes[i]) == h)
        {
            res.push_back(primes[i]);
        }
        i++;
    }
    cout << res.size() << '\n';
    for(int v : res)
    {
        cout << v << '\n';
    }
}

