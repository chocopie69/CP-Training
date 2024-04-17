#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n,k,a[LIMIT],sum[LIMIT], res = 0, res2;

void binarySearch(ll x)
{
    ll left = 1, right = x;
    while(left <= right)
    {
        ll mid = (left + right) / 2;
        ll cur = a[x] * (x - mid + 1) - (sum[x] - sum[mid - 1]);
        if(cur <= k)
        {
            if(x - mid + 1 > res)
            {
                res = x - mid + 1;
                res2 = a[x];
            }
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
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
    sort(a + 1, a + n + 1);
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        binarySearch(i);
    }
    cout << res << " " << res2;
}

