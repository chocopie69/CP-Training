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

ll n;
pll a[SZ];
ll x[SZ], y[SZ], sumX[SZ], sumY[SZ], res = INFLL;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        x[i] = a[i].fi;
        y[i] = a[i].se;
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for(int i = 1; i <= n; i++)
    {
        sumX[i] = sumX[i-1] + x[i];
        sumY[i] = sumY[i-1] + y[i];
        //cout << x[i] << ' ' << y[i] << '\n';
    }
    ll pos = n/2+1;
    ll xDiff = pos * x[pos] - sumX[pos] + (sumX[n] - sumX[pos]) - (n-pos)*x[pos];
    ll yDiff = pos * y[pos] - sumY[pos] + (sumY[n] - sumY[pos]) - (n-pos)*y[pos];
    cout << xDiff + yDiff;
}

