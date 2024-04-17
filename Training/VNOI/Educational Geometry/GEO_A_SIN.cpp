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

ll x = 1, y = 0, x2, y2;

int main()
{
    init();
    cin >> x2 >> y2;
    long double sinval = (long double) (x*y2 - x2*y) / (hypot(x,y) * hypot(x2,y2)), res = asin(sinval);
    //if(sinval < 0) res = (long double) acos(-1) - res;
    cout << fixed << setprecision(7) << res * 180 / acos(-1);
}
