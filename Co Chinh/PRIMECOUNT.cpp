#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "PRIMECOUNT"

using namespace std;

const int LIMIT = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll lo,hi, t;
bool isPrime[LIMIT];
vector<ll> primes;

void segmentedSieve(int lo, int range)
{
    for(int i = lo; i <= range; i++) isPrime[i-lo] = true;
    for(int i = 2; i * i <= range; i++)
    {
        int t = (lo+i-1)/i;
        for(int j = max(i*i,i*t); j <= range; j+=i)
        {
            isPrime[j-lo] = false;
        }
    }
    if(1 >= lo) isPrime[1-lo] = false;
    if(0 >= lo) isPrime[0-lo] = false;
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        int cnt = 0;
        cin >> lo >> hi;
        segmentedSieve(lo, hi);
        for(int i = lo; i <= hi; i++)
        {
            if(isPrime[i-lo]) cnt++;
        }
        cout << cnt << '\n';
    }
}

