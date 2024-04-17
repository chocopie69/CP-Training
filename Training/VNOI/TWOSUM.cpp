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

const int SZ = 5e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, res = 0, x, sum[SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        sum[i] = sum[i-1] + x;
    }
    for(int hi = 2; hi <= n; hi++)
    {
        int lo = 1;
        for(int k = 1; k < hi; k++)
        {
            while(lo < k && sum[k] - sum[lo-1] > sum[hi] - sum[k]) lo++;
            if(sum[k] - sum[lo-1] == sum[hi] - sum[k]) res = max(res, hi - lo + 1);
        }
    }
    cout << res;
}
