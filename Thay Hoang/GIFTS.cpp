#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "GIFTS"

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

int n,k;
ll a[SZ], sum[SZ], maxLo = -INFLL, maxHi[SZ], res = INFLL;

int main()
{
    init();
    cin >> n >> k;
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    maxHi[n-k+2] = -INFLL;
    for(int i = n-k+1; i >= 1; i--)
    {
        int j = i+k-1;
        maxHi[i] = max(maxHi[i+1],sum[j] - sum[i-1]);
    }
    for(int i = 1; i <= n - k + 1; i++)
    {
        int j = i + k - 1;
        if(i > k)
        {
            maxLo = max(maxLo,sum[i-1] - sum[i-k-1]);
        }
        //cout << maxLo << " " << maxHi[j+1] << '\n';
        res = min(res,max(maxLo,maxHi[j+1]));
    }
    cout << res;
}
