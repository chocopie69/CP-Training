#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CARSHOW1"

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

int n,res = 1;
ll t, d;
pll a[SZ];

int main()
{
    init();
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    d = a[n].fi + t*a[n].se;
    for(int i = n-1; i >= 1; i--)
    {
        if(a[i].fi + t*a[i].se < d)
        {
            d = a[i].fi + t*a[i].se;
            res++;
        }
    }
    cout << res;
}
