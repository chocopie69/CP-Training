#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "Eratos"

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

int n;
bool prime[LIMIT+10];

void sieve()
{
    memset(prime,true,sizeof(prime));
    for(int i = 2; i * i <= LIMIT; i++)
    {
        if(prime[i]) for(int j = i*i; j <= LIMIT; j+=i) prime[j] = false;
    }
}

int main()
{
    init();
    cin >> n;
    sieve();
    for(int i = 2; i <= n; i++)
    {
        if(prime[i]) cout << i << " ";
    }
}

