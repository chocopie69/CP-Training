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
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;


ull power(ull x, ull y)
{
    if(y == 0) return 1ULL;
    ull cur = power(x, y/2);
    if(y % 2 == 0) return (cur * cur) % MOD;
    return ( (cur * cur) % MOD * (x % MOD)) % MOD;
}

ull a,b;

int main()
{
    init();
    cin >> a >> b;
    cout << power(a,b);
}

