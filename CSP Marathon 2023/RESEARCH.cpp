#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "RESEARCH"

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

ll n,k, a[SZ], res = 0;

namespace sub1
{
    void solve()
    {
        a[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            res += max(a[i] - a[i-1], 0LL);
        }
        cout << res;
    }
}

namespace sub2
{
    void solve()
    {
        cout << a[n-k];
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
    if(k == 0)
        sub1::solve();
    else sub2::solve();
}
