#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "PALIND"

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

const ll BASE = 311;

string s,t;

int n;
ll hashS[SZ], hashT[SZ], powBase[SZ];

void buildHash()
{
    powBase[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        powBase[i] = (powBase[i-1] * BASE) % MOD;
    }
    hashS[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        hashS[i] = (hashS[i-1] * BASE + int(s[i]) ) % MOD;
    }
    hashT[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        hashT[i] = (hashT[i-1] * BASE + int(t[i])) % MOD;
    }
}

ll getHashS(int lo, int hi)
{
    return (hashS[hi] - hashS[lo-1] * powBase[hi-lo+1] + MOD*MOD) % MOD;
}

ll getHashT(int lo, int hi)
{
    return (hashT[hi] - hashT[lo-1] * powBase[hi-lo+1] + MOD*MOD) % MOD;
}

int main()
{
    init();
    cin >> s;
    t = s;
    reverse(all(t));
    n = s.length();
    t = " " + t;
    s = " " + s;
    cout << s.substr(1);
    buildHash();
    int pos = n;
    for(int i = 1; i <= n; i++)
    {
        if(getHashS(i,n) == getHashT(1,n-i+1))
        {
            pos = i;
            break;
        }
    }
    for(int i = pos-1; i >= 1; i--)
    {
        cout << s[i];
    }
}
