#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> x;

int main()
{
    while(cin >> s)
    {
        x.push_back(s);
    }
    for(int i=x.size()-1;i>=0;i--)
    {
        reverse(x[i].begin(),x[i].end());
        cout << x[i];
    }
}
