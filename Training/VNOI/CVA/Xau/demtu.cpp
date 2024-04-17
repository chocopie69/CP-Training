#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,chu="";
    getline(cin,s);
    s = s + " ";
    int k = 0;
    bool hetchu = true;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == ' ')
        {
            if(hetchu == false)
            {
                k++;
                hetchu = true;
                chu = "";
            }
        } else
        {
            chu+=s[i];
            hetchu = false;
        }
    }
    hetchu = true;
    cout << k << endl;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == ' ')
        {
            if(hetchu == false)
            {
                cout << chu << " ";
                hetchu = true;
                chu = "";
            }
        } else
        {
            chu+=s[i];
            hetchu = false;
        }
    }
}
