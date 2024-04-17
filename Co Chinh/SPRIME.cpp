#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SPRIME"

using namespace std;

const int LIMIT = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll l,r, res = 0;
queue<ll> qu;
bool isPrime[LIMIT];
vector<ll> primes;

void sieve(int range)
{
    memset(isPrime,true,sizeof(isPrime))'
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= range; i++)
    {
        if(isPrime[i]) for(int j = i*i; j <= range; j+=i)
        {
            isPrime[j] = false;
        }
    }
}

int main()
{
    init();
    cin >> l >> r;
    int sqrtr = sqrt(r);
    sieve(sqrtr);
    qu.push(0);
    while(!qu.empty())
    {
        ll cur = qu.top();
        for(int i )
    }
}

