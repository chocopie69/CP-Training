#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SPRIME"

using namespace std;

const int LIMIT = 3e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int t,l,r,res[LIMIT+2];
bool prime[LIMIT+2];

void sieve()
{
    memset(prime,true,sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i * i <= LIMIT; i++)
    {
        if(prime[i]) for(int j = i * i; j <= LIMIT;j+=i)
        {
            prime[j] = false;
        }
    }
}

int check(int x)
{
    if(prime[x] == false) return 0;
    int sum = 0;
    while(x > 0)
    {
        sum += (x % 10);
        x /= 10;
    }
    return (sum % 5 == 0);
}

void preComputation()
{
    res[0] = 0;
    res[1] = 0;
    for(int i = 2; i <= LIMIT; i++)
    {
        res[i] = res[i-1] + check(i);
    }
}

int main()
{
    init();
    sieve();
    preComputation();
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        cout << res[r] - res[l-1] << '\n';
    }
}

