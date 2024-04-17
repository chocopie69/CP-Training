#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,k,a[SZ],sum[SZ], start = -1, res = INFLL;
map<ll,ll> mp;

int main()
{
    init();
    cin >> n >> k;
    sum[0] = 0;
    mp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(mp.find(sum[i] - k) != mp.end())
        {
            ll j = mp[sum[i] - k] + 1;
            //cout << i << " " << j << '\n';
            if(i - j + 1 < res)
            {
                res = i - j + 1;
                start = j;
            }
        }
        mp[sum[i]] = i;
    }
    if(start == -1)
    {
        cout << 0;
    } else
    {
        cout << start << " " << res;
    }
}

/*
21 10
0 2 3 2 10 1 5 5 6 12 20 30 14 8 0 11 0 6 0 0 5

6 2
0 0 1 1 1 1
*/
