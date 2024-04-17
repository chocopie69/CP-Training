#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        int cnt=0,res=0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(')
            {
                cnt++;
            }
            else
            {
                cnt--;
                if(cnt < 0) res++,cnt=0;
            }
        }
        cout << res << '\n';
    }
}
