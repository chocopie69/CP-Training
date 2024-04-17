#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int t;
string s,f,l;

void solve()
{
    if(l + f == s) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> s >> f >> l;
        solve();
    }
}
