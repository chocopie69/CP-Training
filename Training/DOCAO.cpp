#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 2e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

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

int tcs(int x)
{
    int res = 0;
    while(x > 0)
    {
        res += (x % 10);
        x /= 10;
    }
    return res;
}

int n,h, cnt = 0;

int main()
{
    init();
    sieve();
    cin >> n >> h;
    for(int p : primes)
    {
        if(p > n) break;
        if(tcs(p) == h)
        {
            cout << p << '\n';
            cnt++;
        }
    }
    cout << cnt;
}
