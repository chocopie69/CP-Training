#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "LINEUP"

using namespace std;

const int SZ = 3e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, a[SZ];
ll sum, dp[SZ];
stack<int> st;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0] = 1;
    sum = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = dp[i-1];
        while(!st.empty() && a[st.top()] < a[i] )
        {
            sum = (sum - dp[st.top()-1] + MOD) % MOD;
            st.pop();
        }
        dp[i] = (dp[i] + sum) % MOD;
        st.push(i);
        sum = (sum + dp[i-1]) % MOD;
        //cout << dp[i] << " ";
    }
    cout << dp[n];
}
