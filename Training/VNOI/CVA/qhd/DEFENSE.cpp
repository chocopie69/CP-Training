#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int t,n,a[LIMIT],b[LIMIT],res = 1;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        res = 1;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = INF;
        }
        b[0] = -INF;
        for(int i = 1; i <= n; i++)
        {
            int pos = lower_bound(b,b+n+1,a[i]) - b;
            b[pos] = a[i];
            res = max(res,pos);
        }
        cout << res << '\n';
    }
}

