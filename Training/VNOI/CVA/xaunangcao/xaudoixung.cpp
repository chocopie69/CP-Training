#include <bits/stdc++.h>
using namespace std;

const int maxN = 5005;
int n,curLen,maxLen=1;
bool dp[maxN][maxN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s,s1,s2;
    cin >> s;
    memset(dp,false,sizeof(dp));
    for(int i=0;i<n;i++)
        dp[i][i] = true;
    for(int len=2;len<=n;len++)
    {
        for(int i = 0; i <= n-len; i++)
        {
            int j = i+len-1;
            if(len == 2)
            {
                if(s[i] == s[j]) dp[i][j] = true;
            } else
            {
                dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
            }
            if(dp[i][j]) maxLen = max(maxLen,len);
        }
    }
    cout << maxLen;
}
