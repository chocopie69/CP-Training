#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "MAXPRO"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll a[3], m;

ll multi(ll a, ll n, ll m)
{
    if(n == 0) return 0;
    ll cur = multi(a, n/2, m);
    if(n % 2 == 0)
        return (cur + cur) % m;
    return ((cur + cur) % m + a % m) % m;
}

int main()
{
    init();
    cin >> a[0] >> a[1] >> a[2] >> m;
    sort(a,a+3);
    if(a[0] < 0 && a[1] < 0)
    {
        a[0] = -a[0];
        a[1] = -a[1];
        cout << multi(a[0],a[1],m);
    } else
        cout << multi(a[2],a[1],m);
    //cout << multi(-3, -2, 100);
}

