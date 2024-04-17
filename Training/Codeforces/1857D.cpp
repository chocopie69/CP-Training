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

ll t,n,a[SZ],b[SZ];

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll mx = -INFLL, cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> b[i];
            mx = max(mx,a[i] - b[i]);
        }
        for(int i = 1; i <= n; i++)
        {
            if(a[i] - b[i] == mx) cnt++;
        }
        cout << cnt << '\n';
        for(int i = 1; i <= n; i++)
        {
            if(a[i] - b[i] == mx) cout << i << " ";
        }
        cout << '\n';
    }
}
