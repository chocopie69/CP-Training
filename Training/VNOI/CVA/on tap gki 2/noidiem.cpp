#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e4+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,a[LIMIT], dp[LIMIT],trace[LIMIT],idx[LIMIT], res = -INF;

void recur(int i)
{
    if(i == 0) return;
    recur(trace[a[i]]);
    cout << a[i] << " " << i << '\n';
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = INF;
        idx[a[i]] = i;
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        int pos = lower_bound(dp,dp+n+1,a[i]) - dp;
        dp[pos] = a[i];
        trace[a[i]] = (pos == 1 ? 0 : idx[dp[pos-1]]);
        res = max(res, pos);
    }
    cout << res << '\n';
    recur(idx[dp[res]]);
}

