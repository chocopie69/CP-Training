#include <bits/stdc++.h>
#define ll long long
#define N int(1e6)

using namespace std;
int t,n;
int a[N+2],s[N+2];
int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> t;
    for (int i=1;i<=t;i++)
    {
        cin >> n;
        for(int j = 1; j <= n; j++) s[j] = 0;
        cout << 1 << " ";
        s[1]++;
        for (int j=2;j<=n;j++)
        {
            int cur = j;
            if (s[j] == 0) cout << j << " ";
            s[j]++;
            while (cur<=n)
            {
                if (s[cur] == 0)cout << cur << " ";
                s[cur]++;
                cur*=2;
            }
        }
        cout << '\n';
    }
    return 0;
}
