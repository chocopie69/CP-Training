#include <bits/stdc++.h>
#define ll unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "ANDMAX"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, res = 0;

int main()
{
    init();
    cin >> n;
    for(ll bit = 63; bit >= 0; bit--)
    {
        ll cur = (ll)1 << bit;
        if(cur * 3 <= n)
        {
            n -= cur*3;
            res |= cur;
        }
        if(n == 0) break;
        while(3*(cur-1) < n) /// cur-1 == 2^(bit-1) + 2^(bit-2) + ... + 2^0
        {
            n -= cur;
        }
    }
    cout << res;
}

