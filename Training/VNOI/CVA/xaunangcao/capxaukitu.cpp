#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6;
int i = 0;
string s[maxN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> s[i])
    {
        if(i % 2 == 1)
        {
            if(s[i] == "END" && s[i-1] == "END") break;
            sort(s[i-1].begin(),s[i-1].end());
            sort(s[i].begin(),s[i].end());
            if(s[i] == s[i-1]) cout << "same" << '\n';
            else cout << "different" << '\n';
        }
        i++;
    }
}
