#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    cout << int(s.find(' ')) << " " << int(s.rfind(' '));
}
