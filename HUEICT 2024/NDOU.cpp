#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 5e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

string s;
ll res = 0;
int n, sum[26][SZ];

int main()
{
    init();
    cin >> s;
    n = s.length();
    s = " " + s;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            sum[j][i] = sum[j][i-1] + (s[i] - 'a' == j);
            //cout << i << " " << char(j + 'a') << " " << sum[i][j] << '\n';
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int mx = 0;
        for(int j = 0; j < 26; j++)
        {
            int pos = lower_bound(sum[j], sum[j] + i, sum[j][i] - 1) - sum[j];
            mx = max(mx,pos);
        }
        res += 1LL*i-mx;
    }
    cout << res;
}

