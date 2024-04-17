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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int t;
string s;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> s;
        int cnt1 = 0, cnt2 = 0, cnt3 = 0, res = 1;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(') cnt1++;
            else if(s[i] == '[') cnt2++;
            else if(s[i] == '{') cnt3++;
            else if(s[i] == ')') cnt1--;
            else if(s[i] == ']') cnt2--;
            else cnt3--;
            if(cnt1 < 0 || cnt2 < 0 || cnt3 < 0) res = 0;
        }
        if(res == 1 && (cnt1 != 0 || cnt2 != 0 || cnt3 != 0) ) res = 0;
        cout << res << '\n';
    }
}

