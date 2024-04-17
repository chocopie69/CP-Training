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

int n;
pll a[SZ];
ll prefixMax[SZ], prefixMin[SZ], suffixMax[SZ], suffixMin[SZ], res = INFLL;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + n + 1);
    prefixMax[0] = -INFLL;
    prefixMin[0] = INFLL;
    for(int i = 1; i <= n; i++)
    {
        prefixMax[i] = max(prefixMax[i-1], a[i].se);
        prefixMin[i] = min(prefixMin[i-1], a[i].se);
    }
    suffixMax[n+1] = -INFLL;
    suffixMin[n+1] = INFLL;
    for(int i = n; i >= 1; i--)
    {
        suffixMax[i] = max(suffixMax[i+1], a[i].se);
        suffixMin[i] = min(suffixMin[i+1], a[i].se);
    }
//    for(int i = 1; i <= n; i++)
//    {
//        ll mx = -INFLL, mn = INFLL;
//        for(int j = i; j <= n; j++)
//        {
//            if(i == 1 && j == n) continue;
//            mx = max(mx, a[j].fi);
//            mn = min(mn, a[j].fi);
//            res = min(res, mx - mn + max(prefixMax[i-1], suffixMax[j+1]) - min(prefixMin[i-1], suffixMin[j+1]) );
//        }
//    }
    for(int hi = 1; hi <= n; hi++)
    {

    }
    cout << res;
}
