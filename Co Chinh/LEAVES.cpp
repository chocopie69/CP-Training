#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "LEAVES"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,s,a[SZ], b[SZ], res;

ll getBestAnswer(ll x)
{
    ll sum = 0;
    for(ll i = 1; i <= n; i++)
    {
        b[i] = a[i] + i*x;
    }
    sort(b+1,b+n+1);
    for(int i = 1; i <= x; i++)
    {
        sum += b[i];
    }
    return sum;
}

int main()
{
    init();
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll l = 0, r = n, mid;
    while(l <= r)
    {
        mid = (l+r)/2;
        ll cur = getBestAnswer(mid);
        if(cur <= s)
        {
            l = mid+1;
            res = cur;
        }
        else
        {
            r = mid-1;
        }
    }
    cout << r << " " << res;
}

