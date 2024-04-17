#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
using namespace std;

const int INF = INT_MAX, LIMIT = 2e5+5;
const ll INFLL = 2e18;

void init()
{
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int t,n,a[LIMIT],res;
int main()
{
    init();
    cin >> t;
    while(t--)
    {
        res = 1;
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1,a + n + 1);
        endNum[1] = a[1];
        for(int i = 2; i <= n; i++)
        {
            int pos = lower_bound(endNum + 1, endNum + res + 1, a[i]);

        }
    }
}
