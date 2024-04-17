#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SPRIME"

using namespace std;

const int LIMIT = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18, MAXNUM = 1e10+5;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Number
{
    ll val, cnt;
};

ll t,k, res = 0;
queue<Number> qu;
bool isPrime[LIMIT];
vector<ll> primes;

void sieve(int range)
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= range; i++)
    {
        if(isPrime[i]) for(int j = i*i; j <= range; j+=i)
        {
            isPrime[j] = false;
        }
    }
    for(int i = 2; i <= range; i++)
    {
        if(isPrime[i]) primes.push_back(i);
    }
}
bool checkPrime(ll x)
{
    if(x < 2) return false;
    int i = 0;
    while(i < primes.size())
    {
        if(primes[i] * primes[i] > x) return true;
        if(x % primes[i] == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    init();
    ll sqrtr = sqrt(MAXNUM) + 2;
    sieve(sqrtr);
    cin >> t;
    while(t--)
    {
        cin >> k;
        res = 0;
        qu.push({0,0});
        while(!qu.empty())
        {
            Number cur = qu.front();
            qu.pop();
            if(cur.cnt == k)
            {
                res++;
                continue;
            }
            for(int i = 1; i <= 9; i++)
            {
                ll x = cur.val*10 + i;
                if(checkPrime(x))
                {
                    qu.push({x,cur.cnt + 1});
                }
            }
        }
        cout << res << '\n';
    }
}

