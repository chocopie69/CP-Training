#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BEAUTY"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
ll a[SZ], sum[SZ], minOddSum[SZ], minEvenSum[SZ], res = 0;

int main()
{
    init();
    cin >> n;
    sum[0] = 0;
    minOddSum[0] = 0;
    minEvenSum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
        minOddSum[i] = min(minOddSum[i-1], (i % 2 == 1 ? sum[i] : INFLL));
        minEvenSum[i] = min(minEvenSum[i-1], (i % 2 == 0 ? sum[i] : INFLL));
    }
    for(int i = 4; i <= n; i++)
    {
        if(i % 2 == 0)
        {
            res = max(res,sum[i] - minEvenSum[i-4]);
        } else
        {
            res = max(res, sum[i] - minOddSum[i-4]);
        }
    }
    cout << res;
}
