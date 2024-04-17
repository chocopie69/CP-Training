#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "VLN"

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

ll n,h,a[SZ], sum[SZ], res = -INFLL;

int main()
{
    init();
    cin >> n >> h;
    ll len = (h/3) * 2 + 1;
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1; i <= n-len+1; i++)
    {
        int j = i + len - 1;
        res = max(res, sum[j] - sum[i-1]);
    }
    cout << res;
}

