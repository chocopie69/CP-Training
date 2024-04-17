#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,k,a[LIMIT], res = 1, sum = 0;

int main()
{
    init();
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll left = 1, right = INFLL;
    while(left <= right)
    {
        ll mid = (left + right) / 2;
        ll cnt = 1, cur = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] > mid)
            {
                cnt = INFLL;
                break;
            }
            if(cur + a[i] <= mid)
            {
                cur += a[i];
            } else
            {
                cnt++;
                cur = a[i];
            }
        }
        if(cnt <= k)
        {
            res = mid;
            right = mid-1;
        } else
        {
            left = mid+1;
        }
    }
    cout << res;
}
