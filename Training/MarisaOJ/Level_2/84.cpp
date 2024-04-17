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

ll k;

bool check(ll x)
{
    return (x/3 + x/5 + x/7 - x/15 - x/35 - x/21 + x/105) >= k;
}

int main()
{
    init();
    cin >> k;
    ll lo = 3, hi = INFLL;
    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if(check(mid))
        {
            hi = mid-1;
        } else
        {
            lo = mid+1;
        }
    }
    cout << lo;
}

