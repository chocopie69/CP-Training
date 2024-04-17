#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2,s;
    getline(cin,s1);
    getline(cin,s2);
    getline(cin,s);
    while(int(s.find(s1)) != -1)
    {
        s.replace(s.find(s1),s1.length(),s2);
    }
    cout << s;
}
