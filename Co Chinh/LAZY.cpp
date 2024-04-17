#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "LAZY"

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

int n,k,sum[SZ], res = 0;
pii a[SZ];

int lowerBound(int x)
{
    int lo = 1, hi = n, mid;
    while(lo <= hi)
    {
        mid = (lo+hi)/2;
        if(a[mid].fi >= x)
        {
            hi = mid-1;
        } else
        {
            lo = mid+1;
        }
    }
    return lo;
}

int upperBound(int x)
{
    int lo = 1, hi = n, mid;
    while(lo <= hi)
    {
        mid = (lo+hi)/2;
        if(a[mid].fi > x)
        {
            hi = mid-1;
        } else
        {
            lo = mid+1;
        }
    }
    return lo;
}

int main()
{
    init();
    cin >> n >> k;
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        swap(a[i].fi,a[i].se);
    }
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i].se;
    }
    for(int i = a[1].fi; i <= a[n].fi; i++)
    {
        int lo = lowerBound(i-k), hi = upperBound(i+k) - 1;
        res = max(res, sum[hi] - sum[lo-1]);
    }
    cout << res;
}

