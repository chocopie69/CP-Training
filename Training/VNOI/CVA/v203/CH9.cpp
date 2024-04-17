#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CH9"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int t, n;
string s, res;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> s;
        n = s.length();
        s = " " + s;
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            sum += int(s[i]) - 48;
        }
        if(sum % 9 == 0) res = s;
        else res = "";
        int m = (sum-1) % 9 + 1, col;
        bool flag = false;
        for(int i = 1; i <= n; i++)
        {
            int x = int(s[i]) - 48;
            if(x - m >= 0)
            {
                flag = true;
                s[i] = char(x - m + 48);
                res = s;
                break;
            } else if(x + (9-m) <= 9 )
            {
                col = i;
            }
        }
        if(!flag && res == "")
        {
            s[col] = char( int(s[col]) + (9-m) );
            res = s;
        }
        cout << res.substr(1) << '\n';
    }
}
