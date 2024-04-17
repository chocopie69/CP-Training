#include <bits/stdc++.h>
using namespace std;

int dem[26];

int main()
{
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
        s[i] = tolower(s[i]);
        if(s[i] != ' ')
        {
            dem[s[i]-97]++;
        }
    }
    for(int i=0;i<=25;i++)
    {
        if(dem[i] > 0)
            cout << char(i+97) << " " << dem[i] << endl;
    }
}


