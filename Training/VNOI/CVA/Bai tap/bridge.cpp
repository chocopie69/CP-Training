#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll w,n,a[SZ], curSum = 0;

int main()
{
    init();
    cin >> w >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i > 4) curSum -= a[i-4];
        if(curSum + a[i] <= w)
        {
            curSum += a[i];
        }
        else
        {
            cout << i-1;
            return 0;
        }
    }
    cout << n;
}

