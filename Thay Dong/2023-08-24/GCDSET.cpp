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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, res = 0;
ll a[int(1e3)+5];

bool isPrime[SZ];
vector<ll> primes;

void sieve()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 3; i * i < SZ; i += 2)
    {
        if(isPrime[i]) for(int j = i*i; j < SZ; j += i * 2) isPrime[j] = false;
    }
    primes.push_back(2LL);
    for(int i = 3; i < SZ; i += 2)
    {
        if(isPrime[i]) primes.push_back(1LL*i);
    }
}

set<ll> s;
set<ll> vec;
vector<ll> del;

queue<ll> qu;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
//    sieve();
//    for(ll p : primes)
//    {
//        int cnt = 0;
//        for(int i = 1; i <= n; i++)
//        {
//            if(a[i] % p == 0) cnt++;
//        }
//        res = max(res,cnt);
//    }
    qu.push(a[1]);
    s.insert(a[1]);
    for(int i = 2; i <= n; i++)
    {
        while(!s.empty())
        {
            ll u = *s.begin() , v = __gcd(a[i],u);
            s.erase(s.begin());
            if(a[i] / v > 1) vec.insert(a[i] / v);
            if(v > 1) vec.insert(v);
            if(u / v > 1) vec.insert(u / v);
            //cout << u << '\n';
        }
        swap(s,vec);
    }
    for(ll p : s)
    {
        if(p == 1) continue;
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] % p == 0) cnt++;
        }
        res = max(res,cnt);
    }
    cout << res;
}
