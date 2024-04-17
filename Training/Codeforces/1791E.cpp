#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 2e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t,n;
ll a[LIMIT],res,sum;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        res = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for(int i = 2; i <= n; i++)
        {
            int j = i;
            while(j >= 2 && -a[j] - a[j-1] > a[j] + a[j-1])
            {
                a[j] = -a[j];
                a[j-1] = -a[j-1];
                j--;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            res += a[i];
        }
        cout << res << '\n';
    }
}

