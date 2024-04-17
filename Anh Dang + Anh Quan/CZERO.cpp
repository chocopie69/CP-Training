#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CZERO"

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

ll x;
int n,k;
string s;
stack<int> st;

ll dp[32][2][32][2];

ll f(int i, bool les, int sum, bool nz)
{
    if(i == n) return (sum == k && nz);
    ll ans = 0;
    if(dp[i][int(les)][sum][int(nz)] != -1) return dp[i][int(les)][sum][int(nz)];
    for(char c = '0'; c <= '1'; ++c)
    {
        if( (les || c <= s[i+1]) && (c == '1' || sum + int(c == '0' && nz) <= k) )
        {
            ans += f(i+1,les || c < s[i+1], sum + int(c == '0' && nz), nz || c != '0');
        }
    }
    return dp[i][int(les)][sum][int(nz)] = ans;
}

int main()
{
    init();
    while(cin >> x >> k)
    {
        //if(x == -1) break;
        while(x > 0)
        {
            st.push(x % 2);
            x /= 2;
        }
        s = " ";
        while(!st.empty())
        {
            s += char(st.top() + 48);
            st.pop();
        }
        n = s.length() - 1;
        memset(dp,-1,sizeof(dp));
        cout << f(0,false,0,false) << '\n';
    }
}
