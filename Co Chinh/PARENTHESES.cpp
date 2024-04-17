#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "PARENTHESES"

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

int t, cntOpen, cntClose, n, sum[SZ], minNumL[SZ], minNumR[SZ];
string s;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> s;
        n = s.length();
        s = " " + s;
        sum[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            sum[i] = sum[i-1] + (s[i] == '(' ? 1 : -1);
        }
        minNumL[0] = INF;
        for(int i = 1; i <= n; i++)
        {
            minNumL[i] = min(minNumL[i-1], sum[i]);
        }
        minNumR[n+1] = INF;
        for(int i = n; i >= 1; i--)
        {
            minNumR[i] = min(minNumR[i+1],sum[i]);
            //cout << sum[i] << ' ';
        }
        for(int i = 1; i <= n; i++)
        {
            if(sum[n] > 0)
            {
                if(s[i] == ')' ) continue;
                //cout << i << " " << minNumL[i-1] << " " << minNumR[i] << '\n';
                if(minNumL[i-1] >= 0 && minNumR[i] - 2 >= 0)
                {
                    cout << i-1 << " ";
                }
            } else
            {
                if(s[i] == '(') continue;
                if(minNumL[i-1] >= 0 && minNumR[i] + 2 >= 0)
                {
                    cout << i-1 << " ";
                }
            }
        }
        cout << '\n';
    }
}

/*
1
((())(()
*/
