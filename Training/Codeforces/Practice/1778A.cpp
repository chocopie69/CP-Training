#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int INF = INT_MAX, MOD = 1e9+7, LIMIT = 1e5+5;
const ll INFLL = 2e18;

void init()
{
    //freopen(TASKNAME".INP","r",stdin);
    //freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int t,n,a[LIMIT],res,sum;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        res = -INT_MAX,sum = 0;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
            if(i >= 2)
                res = max(res,-2*(a[i] + a[i-1]));
        }
        cout << sum + res << '\n';
    }
}

