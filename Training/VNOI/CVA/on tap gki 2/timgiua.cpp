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

ll l,r,left,right,res, minDif = INFLL;

ll dif(ll x, ll y)
{
    return y*(y+1)/2 - (x-1)*(x)/2;
}

int main()
{
    init();
    cin >> l >> r;
    ll left = l, right = r;
    while(left <= right)
    {
        ll mid = (left + right) / 2;
        if(dif(l,mid) > dif(mid+1,r))
        {
            right = mid-1;
        } else
        {
            left = mid+1;
        }
        if(abs(dif(l,mid) - dif(mid+1,r)) < minDif)
        {
            minDif = abs(dif(l,mid) - dif(mid+1,r));
            res = mid;
        }
    }
    cout << res;
}

