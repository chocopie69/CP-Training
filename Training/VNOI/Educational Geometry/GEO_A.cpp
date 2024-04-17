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
const double epsilon = 1e-3, PI = acos(-1);

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

long double x, y, x2 = 1, y2 = 0;

int main()
{
    init();
    cin >> x >> y;
    long double cosval = (long double) (x*x2 + y*y2) / hypot(x, y), res = acos(cosval);
    if(y < 0) res = (long double) 2 * acos(-1) - res;
    cout << fixed << setprecision(7) << res;
}
