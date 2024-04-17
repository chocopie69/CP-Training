#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "INTERVALS"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n, res = 0;
pll a[LIMIT];

ll binarySearch(ll val)
{
    ll left = 0, right = n - 1,res = n;
    while(left <= right)
    {
        ll mid = (left + right) / 2;
        if(a[mid].first > val)
        {
            right = mid-1;
            res = mid;
        }
        else
        {
            left = mid+1;
        }
    }
    return res;
}

int main()
{
    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n);
    for(int i = 0; i < n - 1; i++)
    {
        ll pos = binarySearch(a[i].second);
        res += pos - i - 1;
    }
    cout << res;
}

