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

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

ll n, a[SZ], mx[SZ], sum, mn, res = -INFLL;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    mx[n+1] = -INFLL;
    sum = 0;
    mn = 0;
    for(int i = n; i >= 1; i--)
    {
        sum += a[i];
        mx[i] = max(mx[i+1], sum - mn);
        mn = min(mn, sum);
    }
    sum = 0;
    mn = 0;
    for(int i = 1; i < n; i++)
    {
        sum += a[i];
        res = max(res, sum - mn + mx[i+1]);
        mn = min(mn, sum);
    }
    cout << res;
}

