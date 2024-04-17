#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SOCHAN"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll l,r, res = 0;

int main()
{
    init();
    cin >> l >> r;
    l++;
    r--;
    if(l % 2 == 1) l++;
    if(r % 2 == 1) r--;
    if(l > r)
    {
        cout << 0;
        return 0;
    }
    res = (r-l+1)/2;
    cout << res+1;
}

