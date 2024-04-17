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
const ll INF = INT_MAX / 2, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

struct Data
{
    ll x,y,z;
    Data(ll _x = 0, ll _y = 0, ll _z = 0) : x(_x), y(_y), z(_z) {}

    Data operator + (const Data& other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    Data operator - (const Data& other) const
    {
        return {x - other.x, y - other.y, z - other.z};
    }

    bool operator < (const Data& other) const
    {
        if(x != other.x)
            return x < other.x;
        if(y != other.y)
            return y < other.y;
        return z < other.z;
    }
};

const Data MOD = {(ll) 1e9 + 7, (ll) 1e9 + 9, (ll) 1e9 + 13};

int n,k, res = 0;
ll dif[SZ];
Data hashCode, powBase[SZ], base;
map<Data,int> mp;

bool isPrime[SZ];
vector<int> primes;

void calc()
{
    base = {3*n + 1, 3*n + 7, 3*n + 11};
    powBase[0] = {1, 1, 1};
    for(int i = 1; i <= k; i++)
    {
        powBase[i] = { (powBase[i-1].x * base.x) % MOD.x, (powBase[i-1].y * base.y) % MOD.y, (powBase[i-1].z * base.z) % MOD.z  };
    }
}

int main()
{
    init();
    cin >> n >> k;
    calc();
    mp[hashCode] = 0;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if(x > 1)
        {
            hashCode = hashCode - powBase[x-1];
        }
        if(x < k)
        {
            hashCode = hashCode + powBase[x];
        }
        if(mp.find(hashCode) == mp.end()) mp[hashCode] = i;
        else res = max(res, i - mp[hashCode]);
    }
    cout << res;
}
