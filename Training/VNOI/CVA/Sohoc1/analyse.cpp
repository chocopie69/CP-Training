#include <bits/stdc++.h>
using namespace std;

int cnt[1005];

int main()
{
    int n;
    while(cin >> n)
    {
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)
        {
            int j=2,cur=i;
            while(j <= cur)
            {
                if(cur % j == 0)
                {
                    cur /= j;
                    cnt[j]++;
                } else j++;
            }
        }
        for(int i=1;i<=n;i++) if(cnt[i] > 0) cout << cnt[i] << " ";
        cout << '\n';
    }
}
