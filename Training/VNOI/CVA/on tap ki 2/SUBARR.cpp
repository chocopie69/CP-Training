#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int SZ = 5e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, a[SZ], sum[SZ], res = 0;
map<ll,ll> mp;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 3; i <= n; i++)
    {
        mp[sum[n] - sum[i-1]]++;
    }
    int i = 1;
    while(i <= n-2)
    {
        if(sum[i]*2 == sum[n] - sum[i])
        {
            if(i > 1)
                mp[sum[n] - sum[i]]--;
            res += mp[sum[i]];
        }
        i++;
    }
    cout << res;
}
