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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

ll n,a,b;
vector<ll> v;

ll res(ll pos)
{
    ll sum = 0, i = 1;
    while(i <= pos)
    {
        ll j = min(pos, n / (n/i) );
        sum += (j - i + 1) * (n/i);
        i = j + 1;
    }
    return sum;
}

int main()
{
    init();
    cin >> n >> a >> b;
    cout << res(b) - res(a-1);
}
