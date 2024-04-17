#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

string s;

void init()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    while(cin >> s)
    {
        s[0] = toupper(s[0]);
        cout << s;
    }
}
