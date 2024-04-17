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
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t;
ll n,a[SZ];

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        a[n+1] = INFLL;
        ll lo = 0, hi = 1e9, mid;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            int i = 1, cnt = 0;
            while(i <= n)
            {
                int cur = a[i];
                i = upper_bound(a+i,a+n+1,cur + mid*2) - a;
                cnt++;
                //cout << i << " ";
            }
            if(cnt <= 3)
            {
                hi = mid-1;
            } else
            {
                lo = mid+1;
            }
        }
        cout << lo << '\n';
    }
}
