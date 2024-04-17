#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "SUBP"

using namespace std;

const int SZ = 2e5+5, k = 1e5+2;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n = 0, res = 0;
string s;
stack<int> st;

int main()
{
    init();
    cin >> s;
    n = s.length();
    s = " " + s;
    st.push(0);
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '(')
        {
            st.push(i);
        } else
        {
            if(st.size() > 1 && s[st.top()] == '(')
            {
                st.pop();
                res = max(res,i-st.top());
            } else
            {
                st.push(i);
            }
        }
    }
    cout << res;
}
