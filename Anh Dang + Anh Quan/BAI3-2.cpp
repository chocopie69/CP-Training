#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BAI3"

using namespace std;

const int SZ = 5e4+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,a[SZ], res = 0, mn[SZ];
pii b[SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> b[i].fi >> b[i].se;
    }
    sort(b + 1, b + m + 1);
    mn[m+1] = INF;
    for(int i = m; i >= 1; i--)
    {
        mn[i] = min(mn[i+1], b[i].se);
    }
    for(int i = 1; i <= n; i++)
    {
        int lo = 1, hi = m, mid;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(b[mid].fi >= a[i])
            {
                hi = mid-1;
            } else
            {
                lo = mid+1;
            }
        }
        //cout << lo << " " << mn[lo] << '\n';
        res += mn[lo];
    }
    cout << res;
}
