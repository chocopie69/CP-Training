#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "EXPRESSION"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = 1e18+5, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

struct bieuThuc
{
    int pos;
    ll a,b;
    bieuThuc(int _pos, ll _a, ll _b)
    {
        pos = _pos;
        a = _a;
        b = _b;
    }
};

string s;
stack<bieuThuc> st;

bool isNum(char c)
{
    return int(c) >= 48 && int(c) <= 57;
}

ll calc(int i, ll a, ll b)
{
    string s1 = s.substr(i-3,3);
    if(s1 == "MAX")
    {
        return max(a,b);
    }
    else if(s1 == "SUM")
    {
        return a + b;
    }
    else if(s1 == "DIF")
    {
        return a - b;
    }
    else if(s1 == "MIN")
    {
        return min(a,b);
    }
    return __gcd(abs(a),abs(b));
}

int main()
{
    init();
    cin >> s;
    int curNum = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            st.push({i,-INF,-INF});
            curNum = 0;
        }
        else if(s[i] == ')')
        {
            ll cur = calc(st.top().pos,st.top().a,(st.top().b == -INF ? curNum : st.top().b));
            st.pop();
            if(st.size() == 0)
            {
                cout << cur;
                break;
            }
            if(st.top().a == -INF)
            {
                st.top().a = cur;
            }
            else
            {
                st.top().b = cur;
            }
            curNum = 0;
        }
        else if(isNum(s[i]))
        {
            curNum = curNum * 10 + int(s[i]) - 48;
        }
        else if(s[i] == ',')
        {
            if(st.top().a == -INF)
            {
                st.top().a = curNum;
                curNum = 0;
            }
        }
    }
}

