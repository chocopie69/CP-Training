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

ll n,a[SZ],cnt[SZ], res = 0;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll b = 0;
        while(a[i] > 0)
        {
            b |= (1 << (a[i] % 10));
            a[i] /= 10;
        }
        cnt[b]++;
    }
    for(int i = 1; i < (1 << 10); i++)
    {
        res += cnt[i]*(cnt[i]-1)/2;
        for(int j = i+1; j < (1 << 10); j++)
        {
            if((i & j) > 0)
            {
                res += cnt[i]*cnt[j];
            }

        }
    }
    cout << res;
}
