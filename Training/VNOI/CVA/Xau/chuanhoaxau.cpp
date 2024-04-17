#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == ' ') s.erase(i,1),cout << i << endl;
        else break;
    }
    bool chucaidau = true;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == ' ')
        {
            if(s[i] == s[i+1]) s.erase(i,1);
            else chucaidau = true;
        }
        else
        {
            if(chucaidau) {
                s[i] = toupper(s[i]);
                chucaidau = false;
            }
            else s[i] = tolower(s[i]);
        }
    }
    cout << s;
}

