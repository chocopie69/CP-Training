#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "COUNTZERO"

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

ll n,cnt2 = 0, cnt5 = 0;

ll dem(ll x, ll y)
{
    ll res = 0, cur = y;
    while(cur <= x)
    {
        res += x/cur;
        cur *= y;
    }
    return res;
}

int main()
{
    init();
    cin >> n;
    cnt2 = dem(n,2);
    cnt5 = dem(n,5);
    cout << min(cnt2,cnt5);
}

