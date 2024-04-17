#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

#define TASKNAME "NAME"

const int SZ = 1e4+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n;
string s;
ll res = 0, dp[20000000];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s;
        ll mask = 0;
        for(char c : s)
        {
            mask |= (1 << (c - 'a') );
        }
        dp[mask]++;
    }
    for(int x = 0; x < 24; x++)
    {
        for(int mask = 0; mask < (1 << 24); mask++)
        {
            if(mask >> x & 1)
            {
                dp[mask] += dp[mask - (1 << x) ];
            }
        }
    }
    for(int mask = 0; mask < (1 << 24); mask++)
    {
        res ^= (n - dp[mask]) * (n - dp[mask]);
    }
    cout << res;
}

