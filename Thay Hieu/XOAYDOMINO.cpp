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

const int SZ = 3e3+5, SZ2 = 2e4+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, dp[SZ][SZ2], sum = 0;
pii a[SZ];
stack<int> st;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        sum += a[i].fi + a[i].se;
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= sum/2; j++)
        {
            dp[i][j] = INF;
        }
       // dp[i][0] = 0;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sum/2; j++)
        {
            if(j >= a[i].fi) dp[i][j] = min(dp[i][j], dp[i-1][ j - a[i].fi ]);
            if(j >= a[i].se) dp[i][j] = min(dp[i][j], dp[i-1][ j - a[i].se ] + 1 );
        }
    }
    int w = sum/2;
    while(w > 0 && dp[n][w] == INF) w--;
    //cout << w << " " << dp[n][w] << " " << dp[n][sum - w] << '\n';
    cout << abs( (sum - w) - w ) << '\n';
    for(int i = n; i >= 1; i--)
    {
        if( w >= a[i].fi && dp[i][w] == dp[i-1][w - a[i].fi] )
        {
            w -= a[i].fi;
        } else
        {
            w -= a[i].se;
            st.push(i);
        }
    }
    cout << st.size() << '\n';
    while(!st.empty())
    {
        cout << st.top() << '\n';
        st.pop();
    }
}
