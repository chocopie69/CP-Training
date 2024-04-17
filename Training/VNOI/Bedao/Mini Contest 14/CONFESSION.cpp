#include <bits/stdc++.h>
using namespace std;

int t,n,k,cnt[26];
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> s;
        for(int i=0;i<26;i++) cnt[i] = 0;
        bool flag = true;
        for(int i=0;i<n/2;i++) cnt[s[i] - 97]++;
            for(int i=int(n/2)+(n%2);i<n;i++) cnt[s[i] - 97]--;
            for(int i=0;i<26;i++) if(cnt[i] != 0) flag = false;
            for(int i=k;i<n/2;i++)
            {
                if(s[i] != s[n-i-1]) flag = false;
            }
            if(flag == false) cout << "No" << '\n';
            else
            {
                for(int i=0;i<n/2;i++) s[i] = s[n-i-1];
                cout << "Yes" << '\n' << s << '\n';
            }
    }
}
