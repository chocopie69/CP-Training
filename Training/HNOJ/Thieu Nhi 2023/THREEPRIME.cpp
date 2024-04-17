#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

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

ll n,a,b,c;

ll lcm(ll x, ll y)
{
    return x*y/__gcd(x,y);
}

int main()
{
    init();
    cin >> a >> b >> c >> n;
    cout << (n/a) + (n/b) + (n/c) - (n/lcm(a,b)) - (n/lcm(b,c)) - (n/lcm(a,c)) + (n/lcm(lcm(a,b),c));
}

