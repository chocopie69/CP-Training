#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "number"

using namespace std;

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, dp[SZ], trace[SZ];

bool isPrime[SZ];
vector<int> primes;

void sieve()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i < SZ; i++)
    {
        if(isPrime[i]) for(int j = i*i; j < SZ; j += i) isPrime[j] = false;
    }
    for(int i = 2; i < SZ; i++)
    {
        if(isPrime[i]) primes.push_back(i);
    }
}

stack<int> st;

int main()
{
    init();
    sieve();
    cin >> n;
    dp[0] = 1;
    if(n == 1)
    {
        cout << 1;
        return 0;
    }
    for(auto p : primes) {
        if(p > n) break;
        for(int i = n; i >= p; i--){
            int powp = 1;
            while(powp <= i){
                if(dp[i] < dp[i-powp]*powp)
                {
                    dp[i] = dp[i-powp]*powp;
                    trace[i] = powp;
                }
                powp*=p;
            }
        }
    }
    cout << dp[n] << '\n';
}
