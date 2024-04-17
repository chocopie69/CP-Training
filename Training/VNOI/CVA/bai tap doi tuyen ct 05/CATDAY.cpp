#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CATDAY"

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

ll n,k,a[SZ];

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll lo = 1, hi = 1e11, mid;
    while(lo <= hi)
    {
        ll sum = 0;
        mid = (lo + hi) / 2;
        for(int i = 1; i <= n; i++)
        {
            sum += a[i] / mid;
        }
        if(sum >= k)
        {
            lo = mid+1;
        } else
        {
            hi = mid-1;
        }
    }
    cout << hi;
}
