#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NTRIVIAL"

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
ll sum[SZ], lo,hi, res;
double mn = 1e13;

void sieve()
{
    for(ll i = 2; i < SZ; i++)
    {
        sum[i] = 1;
    }
    for(ll i = 2; i < SZ; i++)
    {
        for(ll j = i*2; j < SZ; j += i)
        {
            sum[j] += i;
        }
    }
}

int main()
{
    init();
    sieve();
    cin >> lo >> hi;
    for(ll i = lo; i <= hi; i++)
    {
        if( (double)sum[i] / i < mn)
        {
            mn = (double)sum[i]/i;
            res = i;
        }
    }
    cout << res;
}
