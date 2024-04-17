#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "CHIABA"

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

ll a,b;

int main()
{
    init();
    cin >> a >> b;
    ll cur = (b-a);
    if(cur % 3 == 0)
    {
        cout << a + (cur/3) << " " << a + (cur/3) + (cur/3);
    }
    else
    {
        cout << -1;
        return 0;
    }
}
