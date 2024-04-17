#include <bits/stdc++.h>
using namespace std;

int main()
{
    string x,s;
    getline(cin,x);
    getline(cin,s);
    while(int(s.find(x)) != -1)
    {
        s.erase(s.find(x),1);
    }
    cout << s;
}
