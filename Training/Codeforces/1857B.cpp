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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t;
string s;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> s;
        s = "0" + s;
        int prev = s.length()-1;
        for(int i = s.length()-1; i >= 1; i--)
        {
            int cur = int(s[i]) - 48, k = i;
            if(cur >= 5)
            {
                if(s[i-1] != '9')
                {
                    s[i-1] = char(int(s[i-1]) + 1);
                    for(int j = i; j <= prev; j++) s[j] = '0';
                    prev = i-1;
                } else
                {
                    for(int j = i-1; j >= 0; j--)
                    {
                        if(s[j] != '9')
                        {
                            s[j] = char(int(s[j]) + 1);
                            for(int k = j+1; k <= prev; k++) s[k] = '0';
                            prev = j;
                            break;
                        }
                    }
                }
            }
        }
        if(s[0] != '0') cout << s[0];
        for(int i = 1; i < s.length(); i++)
        {
            cout << s[i];
        }
        cout << '\n';
    }
}
