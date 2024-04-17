#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "GIFT"

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

ll n,k,a[SZ], trace[SZ];

void recur(int i, ll sum, bool choosed)
{
    if(i == n+1)
    {
        if(sum % k == 0 && choosed)
        {
            for(int j = 1; j <= n; j++)
            {
                if(trace[j] == 1) cout << j << " ";
                if(trace[j] == -1) cout << -j << " ";
            }
            exit(0);
        }
        return;
    }
    trace[i] = 1;
    recur(i+1,sum + a[i], true);
    trace[i] = -1;
    recur(i+1,sum - a[i], true);
    trace[i] = 0;
    recur(i+1,sum, choosed);
}

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    memset(trace,0,sizeof(trace));
    recur(1,0,false);
    cout << 0;
}
