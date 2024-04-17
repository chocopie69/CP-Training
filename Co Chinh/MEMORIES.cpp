#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "MEMORIES"

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

ll n,k,a[SZ];

bool check(ll x)
{
    ll sum = 0, cnt = 1;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > x) return false;
        if(sum + a[i] <= x)
        {
            sum += a[i];
        } else
        {
            cnt++;
            sum = a[i];
        }
    }
    //if(x <= 20) cout << x << " " << cnt << '\n';
    return cnt <= k;
}

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll lo = 1LL, hi = 1e15, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(check(mid))
        {
            hi = mid-1LL;
        } else
        {
            lo = mid+1LL;
        }
    }
    cout << lo;
}

/*
5 3
3 7 727 8 2
*/
