#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "SUMDIV"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18, LIM = 1e6;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

ll l,r, res = 0;

ll sum(ll x)
{
    return x*(x+1) / 2;
}

ll sum(ll x, ll y)
{
    return sum(y) - sum(x-1);
}

bool valid(ll x)
{
    return (l-1)/x < r/x;
}

vector<pll> segments;

int main()
{
    init();
    cin >> l >> r;
    for(ll x = 1; x < LIM; x++)
    {
        if(valid(x)) res += x;
    }
    for(ll v = 1; v <= 1000; v++)
    {
        ll lo = (l + v - 1) / v, hi = r/v;
        lo = max(lo, LIM);
        if(lo > hi) continue;
        segments.push_back({lo,hi});
    }
    sort(all(segments));
    ll mx = 0;
    for(pll p : segments)
    {
        ll lo = p.fi, hi = p.se;
        if(lo > mx)
        {
            res += sum(lo, hi);
        } else
        {
            if(hi <= mx) continue;
            res += sum(mx+1, hi);
        }
        mx = max(mx, hi);
    }
    cout << res;
}
