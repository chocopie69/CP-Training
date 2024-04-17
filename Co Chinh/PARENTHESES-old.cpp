#include <bits/stdc++.h>
using namespace std;

int n;
string s,res;
stack<char> st;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PARENTHESES.INP","r",stdin);
    freopen("PARENTHESES.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n;
    while(n--)
    {
        cin >> s;
        res = "YES";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if(st.empty())
                {
                    res = "NO";
                    break;
                }
                if(s[i] == ')' && st.top() != '(')
                {
                    res = "NO";
                    break;
                }
                if(s[i] == '}' && st.top() != '{')
                {
                    res = "NO";
                    break;
                }
                if(s[i] == ']' && st.top() != '[')
                {
                    res = "NO";
                    break;
                }
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            res = "NO";
            st.pop();
        }
        cout << res << '\n';
    }
}
