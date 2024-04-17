#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
stack<char> st;
int res;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GOATS.INP","r",stdin);
    freopen("GOATS.OUT","w",stdout);
}

int main()
{
    init();
    cin >> s;
    res = s.length();
    for(int i=0;i<s.length();i++)
    {
        if(!st.empty() && st.top() == '>' && s[i] == '<')
        {
            res -=2;
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    cout << res;
}
