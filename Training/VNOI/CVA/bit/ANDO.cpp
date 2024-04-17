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

const int SZ = 3e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
ull a[SZ], cnt[35], res = 0;
bool avail[SZ];

int main()
{
    init();
    cin >> n;
    memset(avail,true,sizeof(avail));
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int k = 30; k >= 0; k--)
    {
        for(int i = 1; i <= n; i++)
        {
            if((a[i] >> k & 1) == 1 && avail[i])
            {
                cnt[k]++;
            }
        }
        if(cnt[k] < 2) continue;
        res += (1 << k);
        for(int i = 1; i <= n; i++)
        {
            if((a[i] >> k & 1) == 0)
            {
                avail[i] = false;
            }
        }
    }
    cout << res;
}

