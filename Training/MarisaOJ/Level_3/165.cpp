#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+13, INFLL = 2e18, BASE = 331;
const double epsilon = 1e-3;

string s,t;
int n,m;
ll hs[SZ], ht, pBase[SZ];

void buildHash()
{
    hs[0] = 0;
    pBase[0] = 1;
    ht = 0;
    for(int i = 1; i <= n ; i++)
    {
        hs[i] = (hs[i-1] * BASE + int(s[i])) % MOD;
        pBase[i] = (pBase[i-1] * BASE) % MOD;
    }
    for(int i = 1; i <= m; i++)
    {
        ht = (ht*BASE + int(t[i])) % MOD;
    }
}

ll getCode(int lo, int hi)
{
    return ( (hs[hi] - hs[lo-1] * pBase[hi - lo + 1]) % MOD + MOD) % MOD;
}


int main()
{
    init();
    cin >> s >> t;
    n = s.length();
    m = t.length();
    //cout << n << " " << m << " ";
    s = " " + s;
    t = " " + t;
    buildHash();
    int res = 0;
    for(int i = m; i <= n; i++)
    {
        if(getCode(i-m+1, i) == ht) res++;
    }
    cout << res;
}

