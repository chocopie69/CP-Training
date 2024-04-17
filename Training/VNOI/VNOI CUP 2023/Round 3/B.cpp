#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll t,n,a,b,cnt0, cnt1;
bool f[SZ];
string s;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        string res = "NO";
        cin >> n >> a >> b >> s;
        cnt0 = 0;
        cnt1 = 0;
        for(char c : s)
        {
            cnt0 += int(c == '0');
            cnt1 += int(c == '1');
        }
        f[0] = true;
        for(int x = 1; x <= 500; x++)
        {
            f[x] = false;
            for(int i = a; i <= b; i++)
            {
                if(i <= x && f[x-i] == true)
                {
                    f[x] = true;
                    break;
                }
            }
        }
        for(int x = 0; x <= cnt1; x++)
        {
            for(int y = 0; y <= cnt0; y++)
            {
                if(x + y < a || x + y > b) continue;
                if(f[cnt0+x-y]) res = "YES";
            }
            //if(f[cnt0+x] && f[x]) res = "YES";
        }
        cout << res << '\n';
    }
}

