#include <bits/stdc++.h>
using namespace std;

int t,n;
string s;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == 'U') s[i] = 'D';
            else if(s[i] == 'D') s[i] = 'U';
        }
        cout << s << '\n';
    }
}
