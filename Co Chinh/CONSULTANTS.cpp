#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "CONSULTANTS"

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

ll n,m,a[SZ];

bool check(ll x)
{
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += (x/a[i]);
    }
    return sum >= m;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll lo = 0, hi = 1e14+5;
    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if(check(mid))
        {
            hi = mid-1;
        } else
        {
            lo = mid+1;
        }
    }
    cout << lo;
}

