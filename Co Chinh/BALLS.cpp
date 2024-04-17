#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BALLS"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,q, c[SZ], last[SZ], pos[SZ];
ll a[SZ], dp[SZ];
pll mx1, mx2;

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++)
    {
        last[i] = pos[c[i]];
        pos[c[i]] = i;
        //cout << last[i] << " ";
    }
    while(q--)
    {
        ll x,y, res = -INFLL;
        cin >> x >> y;
        mx1 = {0,0};
        mx2 = {0,0};
        for(int i = 1; i <= n; i++) dp[i] = 0;
        for(int i = 1; i <= n; i++)
        {
            ll cur;
            if(mx1.se != c[i]) cur = mx1.fi;
            else if(mx2.se != c[i]) cur = mx2.fi;
            else cur = 0;
            if(last[i] == 0)
            {
                dp[c[i]] = cur + a[i]*y;
            } else
            {
                dp[c[i]] = max(dp[c[i]] + a[i]*x, cur + a[i]*y);
            }
            //cout << dp[i] << '\n';
            if(dp[c[i]] > mx1.fi)
            {
                if(mx1.se != c[i])
                    mx2 = mx1;
                mx1 = {dp[c[i]],c[i] };
            } else if(dp[c[i]] > mx2.fi && c[i] != mx1.se)
            {
                mx2 = {dp[c[i]], c[i]};
            }
            cout << i << " " << dp[c[i]] << " " << cur << '\n';
            res = max(res, dp[c[i]]);
        }
        //for(int i = 1; i <= n; i++) res = max(res, dp[i]);
        //cout << res << '\n';
        //cout << dp[n] << '\n';
    }
}

/*
10 1
-167 -209 439 335 -464 -402 -227 132 -82 415
1 2 2 6 8 4 2 6 7 7
-420 -22
*/
