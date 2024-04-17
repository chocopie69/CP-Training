#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "CLIS"

using namespace std;

const int SZ = 500+5, MAXA = 1e5+3;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,a[SZ],b[SZ],dp[SZ][SZ], res = 1;
vector<int> pos[MAXA];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> b[i];
        pos[b[i]].push_back(i);
    }
    for(int i = 0; i <= max(n,m); i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    a[0] = 0;
    b[0] = 0;
    pos[0].push_back(0);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i] != b[j])
                continue;
            for(int k = 0; k < i; k++)
            {
                if(pos[a[k]].empty() || pos[a[k]][0] >= j || a[k] >= a[i]) continue;
                int t = lower_bound(pos[a[k]].begin(), pos[a[k]].end(),j) - pos[a[k]].begin() - 1;
                dp[i][j] = max(dp[i][j],dp[k][pos[a[k]][t]] + 1);
                //cout << i << " " << j << " " << k << ' ' << t << " " <<  dp[i][j] << '\n';
            }
            //cout << i << " " << j << " " << dp[i][j] << '\n';
            res = max(res,dp[i][j]);
        }
    }
    cout << res;
}

