#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

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

ll n,k,a[SZ],b[SZ],cnt[SZ], res = 0;

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            ll curMin = INFLL, curSum = 0;
            for(int x = 1; x <= k; x++)
            {
                cnt[x] = 0;
            }
            for(int x = i; x <= j; x++)
            {
                cnt[a[x]] += b[x];
            }
            for(int x = 1; x <= k; x++)
            {
                curMin = min(curMin,cnt[x]);
                curSum += cnt[x];
            }
            res = max(res,curSum-curMin*k);
        }
    }
    cout << res;
}

