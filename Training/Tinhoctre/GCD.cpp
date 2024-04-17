#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e7+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,a[SZ],b[SZ],cnt[SZ][2],minPrime[SZ], res = 1;
bool vis[SZ];
vector<ll> num;

ll power(ll a, ll n, ll m)
{
    if(n == 0) return 1;
    ll cur = power(a,n/2,m);
    if(n % 2 == 0)
        return (cur * cur) % m;
    else
        return ((cur * cur) % m * a % m) % m;
}

void phantich(ll x, int y)
{
    while(x != 1)
    {
        ll p = minPrime[x];
        if(!vis[p])
        {
            num.push_back(p);
            vis[p] = true;
        }
        cnt[p][y]++;
        x /= p;
    }
}

void sieve()
{
    for(int i = 2; i < SZ; i++)
    {
        minPrime[i] = i;
    }
    for(int i = 2; i < SZ; i += 2)
    {
        minPrime[i] = 2;
    }
    for(int i = 3; i * i < SZ; i += 2)
    {
        if(minPrime[i] == i) for(int j = i * i; j < SZ; j += i*2)
        {
            minPrime[j] = i;
        }
    }
}


int main()
{
    init();
    sieve();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        phantich(a[i],0);
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> b[i];
        phantich(b[i],1);
    }
    for(ll cur : num)
    {
        res = (res * power(cur,min(cnt[cur][0],cnt[cur][1]),MOD)) % MOD;
    }
    cout << res;
}

