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
const ll INF = INT_MAX / 2, MOD = 1e9+11, INFLL = 2e18, BASE = 331, BASE2 = 317;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

string s, t;
int n,m;
ll powBase[SZ], powBase2[SZ], hashS[SZ], hashT[SZ], hashS2[SZ], hashT2[SZ];

void buildHash()
{
    powBase[0] = 1;
    for(int i = 1; i <= 2*n; i++)
    {
        powBase[i] = (powBase[i-1] * BASE) % MOD;
    }
    for(int i = 1; i <= 2*n; i++)
    {
        hashS[i] = (hashS[i-1] * BASE + int(s[i])) % MOD;
        hashT[i] = (hashT[i-1] * BASE + int(t[i])) % MOD;
    }
    powBase2[0] = 1;
    for(int i = 1; i <= 2*n; i++)
    {
        powBase2[i] = (powBase2[i-1] * BASE2) % MOD;
    }
    for(int i = 1; i <= 2*n; i++)
    {
        hashS2[i] = (hashS2[i-1] * BASE2 + int(s[i])) % MOD;
        hashT2[i] = (hashT2[i-1] * BASE2 + int(t[i])) % MOD;
    }
}

ll getHashS(int lo, int hi)
{
    return ((hashS[hi] - hashS[lo-1] * powBase[hi-lo+1]) % MOD + MOD) % MOD;
}

ll getHashT(int lo, int hi)
{
    return ((hashT[hi] - hashT[lo-1] * powBase[hi-lo+1]) % MOD + MOD) % MOD;
}

ll getHashS2(int lo, int hi)
{
    return ((hashS2[hi] - hashS2[lo-1] * powBase2[hi-lo+1]) % MOD + MOD) % MOD;
}

ll getHashT2(int lo, int hi)
{
    return ((hashT2[hi] - hashT2[lo-1] * powBase2[hi-lo+1]) % MOD + MOD) % MOD;
}

map<ll,int> mp, mp2;

bool check(int x)
{
    if(x == 0) return true;
    mp.clear();
    mp2.clear();
    for(int i = 1; i <= n; i++)
    {
        mp[getHashT(i, i + x - 1)] = i;
        mp2[getHashT2(i, i + x - 1)] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        if(mp.find(getHashS(i, i + x - 1) ) != mp.end() && mp2.find(getHashS2(i, i + x - 1) ) != mp2.end())
        {
            //cout << i << " - " << i + x - 1 << '\n';
            return true;
        }
    }
    return false;
}

int main()
{
    init();
    cin >> s >> t;
    n = s.length();
    m = t.length();
    s += s;
    t += t;
    s = " " + s;
    t = " " + t;
    //cout << s << " " << t << '\n';
    buildHash();
    int lo = 0, hi = n, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(check(mid))
        {
            lo = mid+1;
        } else
        {
            hi = mid-1;
        }
    }
    cout << hi;
}
