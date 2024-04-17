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

const int SZ = 3e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

bool isPrime[SZ];
int res[SZ];

bool tcs(int x)
{
    int s = 0;
    while(x > 0)
    {
        s += (x % 10);
        x /= 10;
    }
    return s % 5 == 0;
}

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
        res[i] = res[i-1] + (isPrime[i] && tcs(i));
    }
}

int main()
{
    init();
    sieve();
    int t,l,r;
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        cout << res[r] - res[l-1] << '\n';
    }
}
