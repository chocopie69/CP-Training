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

int n;
pll a[SZ];
ll mx1[SZ], mx2[SZ], sum[SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].se;
    }
    sort(a + 1, a + n + 1, greater<pll>());
    mx1[0] = -INFLL;
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        mx1[i] = max(mx1[i-1], a[i].se - a[i].fi);
        sum[i] = sum[i-1] + a[i].fi;
    }
    mx2[n+1] = -INFLL;
    for(int i = n; i >= 1; i--)
    {
        mx2[i] = max(mx2[i+1], a[i].se);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << max(sum[i] + mx1[i], sum[i-1] + mx2[i]) << '\n';
    }
}

