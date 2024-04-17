#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "FISHPOOL"

using namespace std;

const int LIMIT = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t;
ll n,k,m,a[LIMIT];

int main()
{
    init();
    cin >> t;
    a[0] = -INFLL;
    while(t--)
    {
        ll res = 0;
        cin >> n >> k >> m;
        ll idx = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        a[n+1] = INFLL;
        if(k == m)
        {
            cout << 0 << '\n';
            continue;
        }
        if(k < a[1])
        {
            cout << -1 << '\n';
            continue;
        }
        while(k < m)
        {
            while(a[idx+1] <= k)
            {
                idx++;
            }
            ll x;
            x = min(a[idx+1]-k,m-k);
            x = x/a[idx] + (x % a[idx] != 0);
            res += x;
            k += a[idx]*x;
        }
        cout << res << '\n';
    }
}

/*
1
6 2 12
1 4 6 8 9 11
*/

