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

ll n,k,t = 2;

ll tcs(ll x)
{
    ll res = 0, cur = x;
    while(cur > 0)
    {
        res += (cur % 10);
        cur /= 10;
    }
    return res;
}

int main()
{
    init();
    while(t--)
    {
        cin >> n >> k;
        ll res = 0, times = n/k;
        for(ll i = k; i <= n; i+=k)
        {
            res += tcs(i);
        }
        cout << res << '\n';
    }
}

