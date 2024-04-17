#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "PAYMENT"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int t;
ll n;

ll sum(ll x, ll y)
{
    return (x + y) * ( (y-x) / 5 + 1 ) / 2;
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll cnt5 = 0, res = 0, cnt2 = 0;
        cnt5 = (n / 5);
        n -= 5*cnt5;
        ll d;
        if(n % 2 == 0) d = 2LL;
        else d = 3LL;
        cnt2 = (n / 2);
        cnt5++;
        if(cnt5 % 2 == 0)
        {
            res += sum(0LL, 5LL*(cnt5 / 2 - 1) ) + sum(d, d + 5LL*(cnt5 / 2 - 1) ) + cnt5 * (cnt2 + 1) ;
            //cout << res << ' ';
        } else
        {
            res += sum(0LL, 5LL*(cnt5 / 2) ) + sum(d, d + 5LL*(cnt5 / 2 - 1) ) + cnt5 * (cnt2 + 1);
        }
        cout << res << '\n';
    }
}
