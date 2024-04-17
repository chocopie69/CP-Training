#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "DOIXUNG"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18, BASE = 311;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s,t;
ll powBase[SZ],hashS[SZ],hashT[SZ], res = 0;
int len;

ll getHashS(int i, int j)
{
    return ((hashS[j] - hashS[i-1] * powBase[j-i+1]) % MOD + MOD) % MOD;
}

ll getHashT(int i, int j)
{
    return ((hashT[j] - hashT[i-1] * powBase[j-i+1]) % MOD + MOD) % MOD;
}

void calculate()
{
    powBase[0] = 1;
    for(int i = 1; i <= len; i++)
    {
        powBase[i] = (powBase[i-1] * BASE) % MOD;
        hashS[i] = (hashS[i-1]*BASE + int(s[i])) % MOD;
        hashT[i] = (hashT[i-1]*BASE + int(t[i])) % MOD;
    }
}

bool check(pii x, pii y)
{
    if(x.fi < 1 || y.se > len) return false;
    return getHashS(x.fi,x.se) == getHashT(len-y.se+1,len-y.fi+1);
}

void solveOdd(int x)
{
    int lo = 1, hi = len/2+1, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(check({x-mid+1,x},{x,x+mid-1}))
        {
            lo = mid+1;
        } else
        {
            hi = mid-1;
        }
    }
    res += hi;
}

void solveEven(int x)
{
    int lo = 1, hi = len/2+1, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(check({x-mid+1,x},{x+1,x+mid}))
        {
            lo = mid+1;
        } else
        {
            hi = mid-1;
        }
    }
    res += hi;
}

int main()
{
    init();
    cin >> s;
    t = s;
    len = s.length();
    reverse(t.begin(),t.end());
    s = " " + s;
    t = " " + t;
    calculate();
    for(int i = 1; i <= len; i++)
    {
        solveOdd(i);
        if(i < len) solveEven(i);
    }
    cout << res;
}

