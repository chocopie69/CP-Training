#include <bits/stdc++.h>
using namespace std;
int main ()
{
    string x;
    getline(cin,x);
    string s;
    getline(cin,s);
    int dem = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s.substr(i,1) == x) dem++;
    }
    // s[i] : char
    // s.substr(i,1) : string
    cout << dem << endl;
    for(int i=0;i<s.size();i++)
    {
        if(s.substr(i,1) == x) cout << i << " ";
    }
}
