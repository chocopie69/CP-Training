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

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, lo, hi;
string a[SZ];

bool cmp(string x, string y)
{
    return x+y > y+x;
}

string dp[SZ][SZ];

int main()
{
    init();
    cin >> n >> lo >> hi;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < SZ; i++)
    {
        for(int j = 0; j < SZ; j++)
        {
            dp[i][j] = "";
        }
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= hi; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(a[i].length() <= j)
            {
                if( (j - a[i].length() == 0 || dp[i-1][j-a[i].length()] != "" ) && dp[i-1][j - a[i].length()] + a[i] > dp[i][j]) dp[i][j] = dp[i-1][j - a[i].length()] + a[i];
            }
        }
    }
    string res = "";
    for(int j = lo; j <= hi; j++)
    {
        if(dp[n][j] > res) res = dp[n][j];
    }
    cout << (res == "" ? "-1" : res);
}
