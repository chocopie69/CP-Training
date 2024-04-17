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

ll t,n,a[SZ];

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll cnt1 = 0,sum = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if(a[i] == 1)
            {
                cnt1++;
            } else
            {
                sum += (a[i] - 1);
            }
        }
        if(n == 1 || cnt1 > sum)
        {
            cout << "NO" << '\n';
        } else
        {
            cout << "YES" << '\n';
        }
    }
}