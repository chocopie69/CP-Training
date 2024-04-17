#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "BONUS"

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

ll m, n, w, h, a[SZ], b[SZ], sumA[SZ], sumB[SZ], maxSumB = -INFLL, res = -INFLL;

int main()
{
    init();
    cin >> m >> n >> w >> h;
    sumA[0] = 0;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i];
        sumA[i] = sumA[i-1] + a[i];
    }
    sumB[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        sumB[i] = sumB[i-1] + b[i];
        if(i >= h)
        {
            maxSumB = max(maxSumB, sumB[i] - sumB[i-h]);
        }
    }
    for(int i = 1; i <= m-w+1; i++)
    {
        int j = i+w-1;
        res = max(res, (sumA[j] - sumA[i-1])*h + maxSumB*w );
    }
    cout << res;
}
