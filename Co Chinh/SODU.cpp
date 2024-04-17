#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e7+5;
const ll INF = INT_MAX / 2, MOD = 20230401, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll res = 0, pow10[LIMIT],n, cnt = 0;

ll cs(ll x)
{
    ll cnt = 0;
    while(x > 0)
    {
        cnt++;
        x/=10;
    }
    return cnt;
}

int main()
{
    init();
    pow10[0] = 1;
    for(int i = 1; i < LIMIT;i++)
    {
        pow10[i] = pow10[i-1]*10;
        pow10[i] %= MOD;
    }
    cin >> n;
    for(ll i = n; i >= 1; i--)
    {
        res = (res + (i % MOD * pow10[cnt]) % MOD) % MOD;
        cnt += cs(i);
    }
    cout << res;
}

