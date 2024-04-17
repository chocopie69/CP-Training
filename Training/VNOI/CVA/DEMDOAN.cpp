#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "DEMDOAN"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

ll n, res = 0;

bool check(ll x)
{
    return (2*n) % x == 0 && (2*n/x) % 2 != x % 2;
}

int main()
{
    init();
    cin >> n;
    ll len = 1, sum = 1;
    while(sum <= n)
    {
        if(check(len)) res++;
        len++;
        sum += len;
    }
    cout << res;
}
