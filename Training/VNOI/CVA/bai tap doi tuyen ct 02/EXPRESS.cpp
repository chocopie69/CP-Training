#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "express"

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

ll n,a[SZ],sum[SZ], res = 0;

int main()
{
    init();
    cin >> n;
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1; i <= n-2; i++)
    {
        for(int j = i+1; j <= n-1; j++)
        {
            res = max(res,sum[n] - a[i] - a[i+1] - (i+1 == j ? 0 : a[j]) - a[j+1] + (i+1 == j ? a[i] * a[j] * a[j+1] : a[i]*a[i+1] + a[j]*a[j+1] ) );
        }
    }
    cout << res;
}
