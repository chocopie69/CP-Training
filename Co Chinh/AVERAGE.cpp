#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "AVERAGE"

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

ll n,k,a[LIMIT], res = 0, sum = 0;
map<ll, ll> mp;

int main()
{
    init();
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] -= k;
    }
    for(ll i = 0; i < n; i++)
    {
        sum += a[i];
        if(mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        } else
        {
            res = max(res,i-mp[sum]);
        }
    }
    cout << res;
}

