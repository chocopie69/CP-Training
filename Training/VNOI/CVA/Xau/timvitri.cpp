#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,x;
    getline(cin,x);
    getline(cin,s);
    int cnt = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s.substr(i,1) == x) cnt++;
    }
    cout << cnt << '\n';
    for(int i=0;i<s.length();i++)
    {
        if(s.substr(i,1) == x) cout << i << " ";
    }
}
