#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int giaithua(int n)
{
    int gay = 1;
    for(int i = 1; i <= n; i++)
    {
        gay *= i;
    }
    return gay;
}

int a(int k, int n)
{
    return giaithua(n) / giaithua(n - k);
}

signed main()
{
    init();
    cout << a(2,7) << " " << a(3,7) << " " << " " << 7*7*7 << " " << 1 - ( (long double) (a(2,7) + a(3,7)) / (7*7*7));
}
