#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "COIN"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,k,sum[SZ], res = 0;
map<ll,ll> mp;

int main()
{
    init();
    cin >> n >> k;
    sum[0] = 0;
    mp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if(c == 'O')
        {
            sum[i] = sum[i-1] + 1;
        } else
        {
            sum[i] = sum[i-1] - k;
        }
        if(mp.find(sum[i]) != mp.end())
        {
            res = max(res,i-mp[sum[i]]);
        } else
        {
            mp[sum[i]] = i;
        }
    }
    cout << res;
}

