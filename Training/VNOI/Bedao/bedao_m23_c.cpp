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

int t;
ull x,k;

ull calc(ll v)
{
    return v - ( v/2 + v/3 + v/5 + v/7 - v/(2*3) - v/(2*5) - v/(2*7) - v/15 - v/21 - v/35 + v/(2*3*5) + v/(2*3*7) + v/(2*5*7) + v/(3*5*7) - v/(2*3*5*7) );
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> x >> k;
        ull lo = 1, hi = 1e19;
        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;
            if(calc(mid) >= k)
            {
                hi = mid-1;
            } else
            {
                lo = mid+1;
            }
        }
        cout << calc(x) << " " << lo << '\n';
    }
}

