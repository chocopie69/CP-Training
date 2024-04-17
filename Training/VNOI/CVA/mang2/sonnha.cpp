#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,res=0;
string s;

void solve()
{
    for(int i=1;i<s.length();i++)
    {
        if(s[i] == s[i-1])
        {
            res++;
            s[i] = ' ';
        }
    }
    cout << res;
}

int main()
{
    cin >> n >> s;
    solve();
}
