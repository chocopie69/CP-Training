#include <bits/stdc++.h>
using namespace std;

pair<string,string> s;
int n;

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> s.first >> s.second;
        cout << s.second << " " << s.first << '\n';
    }
}
