#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,k,a[LIMIT], sum = 0, res = 0;
map<ll,ll> mp;


int main()
{
    init();
    cin >> n >> k;
    mp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        ll cur = (sum%k)+k;
        cur %= k;
        res += mp[cur];
        //cout << mp[cur] << " " << cur << '\n';
        mp[cur]++;
    }
    cout << res;
}

