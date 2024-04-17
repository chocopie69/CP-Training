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
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t;
ll n, x, y;

bool scp(ll x)
{
    ll cur = sqrt(x);
    return cur*cur == x;
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(ll i = 1; i * i <= n; i++)
        {
            if(n % i != 0) continue;
            ll j = n/i;
            if(scp(i))
        }
    }
}
