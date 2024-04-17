#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    s=" "+s;
    string r;
    for(int i=1;i<s.length();i++)
    {
        if(s[i-1]==32&&s[i]>=97&&s[i]<=122)
        {
            r+=s[i]-32;
        }
        else if(s[i-1]==32&&s[i]>=65&&s[i]<=90)
        {
            r+=s[i];
        }
        else if(s[i-1]>=97&&s[i-1]<=122||s[i-1]>=65&&s[i-1]<=90)
        {
            if(s[i]>=65&&s[i]<=90)
            {
                r+=s[i]+32;
            }
            else
            {
                r+=s[i];
            }
        }
    }
    cout<<r;
}
