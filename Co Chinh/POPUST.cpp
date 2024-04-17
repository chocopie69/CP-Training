#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "POPUST"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,minNum[SZ],maxDif[SZ], sum[SZ];
pll a[SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        swap(a[i].fi,a[i].se);
    }
    sort(a+1,a+n+1);
    maxDif[0] = -INFLL;
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        maxDif[i] = max(maxDif[i-1],a[i].fi-a[i].se);
        sum[i] = sum[i-1] + a[i].fi;
    }
    minNum[n+1] = INFLL;
    for(int i = n; i >= 1; i--)
    {
        minNum[i] = min(minNum[i+1],a[i].se);
    }
    for(int i = 1; i <= n; i++)
    {
        cout << min(sum[i] - maxDif[i],sum[i-1] + minNum[i]) << '\n';
    }
}
