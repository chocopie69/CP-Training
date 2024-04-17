#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "AWARDS"

using namespace std;

const int SZ = 5e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin);
    freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
ll a[SZ], sum[SZ];
pll dp[SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sum[n+1] = 0;
    for(int i = n; i >= 1; i--)
    {
        sum[i] = sum[i+1] + a[i];
    }
    dp[n] = {1,a[n] };
    for(int i = n-1; i >= 1; i--)
    {
        dp[i] = {1,sum[i]};
        for(int j = i+1; j <= n; j++)
        {
            if(sum[i] - sum[j] >= dp[j].se && dp[i].fi < dp[j].fi + 1)
            {
                dp[i] = {dp[j].fi + 1, sum[i] - sum[j] };
            }
        }
    }
    cout << dp[1].fi;
//    cout << " " << sum[3] - sum[4];
}

/*
5
6 2 8 3 4

4
2 1 2 1
*/
