#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    long long cnt1=0,cnt2=0,res=0;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i] == 'W') cnt1++;
        else if(s[i] == 'O') cnt2+=cnt1;
        else res += cnt2;
    }
    cout << res;
}
