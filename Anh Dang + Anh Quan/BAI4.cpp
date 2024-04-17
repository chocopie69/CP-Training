#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BAI4"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18, BASE = 313;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

string s;
int n;

ll hashVal[SZ], powBase[SZ];

void buildHash()
{
    powBase[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        powBase[i] = (powBase[i-1] * BASE) % MOD;
    }
    hashVal[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        hashVal[i] = ( hashVal[i-1]*BASE + int(s[i]) ) % MOD;
    }
}

ll getHash(int lo, int hi)
{
    return  ( hashVal[hi] - hashVal[lo-1] * powBase[hi - lo + 1] + MOD*MOD) % MOD;
}

bool check(int x)
{
    int k = x * (n / x);
    ll cur = getHash(1, x);
    for(int i = x*2; i <= k; i += x)
    {
        if(getHash(i - x + 1, i) != cur) return false;
    }
    if(k == n) return true;
    return getHash(1, n-k) == getHash(k+1, n);
}

int main()
{
    init();
    cin >> s;
    n = s.length();
    s = " " + s;
    buildHash();
    for(int len = 1; len <= n; len++)
    {
        if(check(len)) cout << len << " ";
    }
}
