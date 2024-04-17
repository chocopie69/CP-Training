#include <bits/stdc++.h>
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

int t, n, c, a[SZ];

bool check(int x)
{
    int prev = a[1], need = c-1;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] - prev >= x)
        {
            need--;
            prev = a[i];
        }
        if(need == 0) return true;
    }
    return false;
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int lo = 0, hi = a[n] - a[1], mid;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(check(mid))
            {
                lo = mid+1;
            } else
            {
                hi = mid-1;
            }
        }
        cout << hi << '\n';
    }
}
