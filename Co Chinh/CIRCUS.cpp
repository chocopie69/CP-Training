#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CIRCUS"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, dp[SZ];

bool isPrime[SZ];
vector<int> primes, v;

void sieve()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i < SZ; i++)
    {
        if(isPrime[i]) for(int j = i*i; j < SZ; j += i) isPrime[j] = false;
    }
    for(int i = 2; i <= n; i++)
    {
        if(isPrime[i]) primes.push_back(i);
    }
}

void trace(int x)
{
    for(int i = primes.size()-1; i >= 0; i--)
    {
        if(primes[i] > x) continue;
        ll powp = 1;
        for(int j = 0; j <= n; j++)
        {
            if(powp > x) break;
            if(dp[x] == dp[x-powp]*powp)
            {
                v.push_back(powp);
                x -= powp;
                break;
            }
            powp *= primes[i];
        }
    }
}

int main()
{
    init();
    cin >> n;
    sieve();
    dp[0] = 1;
    dp[1] = 1;
    for(ll p : primes)
    {
        for(int i = n; i >= 2; i--)
        {
            ll powp = p;
            for(int j = 1; j <= n; j++)
            {
                if(powp > i) break;
                if(i == n && dp[i-powp]*powp > dp[i])
                {
                    //cout << p << " " << powp << '\n';
                }
                dp[i] = max(dp[i],dp[i-powp]*powp);
                powp *= p;
            }
        }
    }
    trace(n);
//    for(ll x : v)
//    {
//        cout << x << " ";
//    }
//    cout << '\n';
    int s = v.back(), prev = 1;
    for(int i = 1; i <= n; i++)
    {
        if(s > 1)
        {
            cout << i << " " << i+1 << " ";
            s--;
        } else
        {
            cout << i << " " << prev << " ";
            prev = i+1;
            v.pop_back();
            s = v.back();
        }
    }
    cout << '\n';
    cout << dp[n];
}
