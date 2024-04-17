#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 2e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-4;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n,k,a[LIMIT];
double sum[LIMIT], minSum[LIMIT], res;

void binarySearch()
{
    double left = -1e9, right = 1e9;
    while(right - left > epsilon)
    {
        bool valid = false;
        double mid = (left + right) / 2;
        sum[0] = 0.0;
        minSum[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            sum[i] = sum[i-1] + a[i] - mid;
            minSum[i] = min(minSum[i-1],sum[i]);
            /// cout << maxSum[i] << '\n';
        }
        for(int i = k; i <= n; i++)
        {
            /// if(mid <= 12.0 && mid >= 8.0) cout << sum[i] << " " << minSum[i-k] << " " << mid << '\n';
            if(sum[i] - minSum[i - k] >= 0)
            {
                valid = true;
            }
        }
        if(valid)
        {
            res = mid;
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
}

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    binarySearch();
    cout << fixed << setprecision(3) << res;
}

/*
22 18
-29 98 45 -72 26 -57 44 97 -24 13 -85 102 80 54 -9 45 -75 -32 35 -91 57 -98
*/
