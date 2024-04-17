#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 5005;
long long n,m=0,a[LIMIT],b[LIMIT],cnt[LIMIT],res=0;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TRIANGLES.INP","r",stdin);
    freopen("TRIANGLES.OUT","w",stdout);
    memset(b,0,sizeof(b));
    memset(cnt,0,sizeof(cnt));
}

void solve()
{
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if((i == 1) || a[i] != a[i-1])
        {
            m++;
            b[m] = a[i];
        }
        cnt[m]++;
    }

    // Dem so tam giac deu
    for(int i=1;i<=m;i++)
    {
        if(cnt[i] >= 3) res++;
    }

    // Dem so tam giac can (khong duoc deu)
    int k = 1;
    for(int i=1;i<=m;i++)
    {
        if(cnt[i] >= 2)
        {
            while(k <= m && b[k] < b[i] * 2)
                k++;
            res += k-2;  // Khong tinh b[i]
        }
    }

    // Dem so tam giac thuong
    for(int i=1;i<=m-2;i++)
    {
        k = i+2;
        for(int j=i+1;j<=m-1;j++)
        {
            while(k <= m && b[k] < b[i] + b[j]) k++;
            res += k-j-1; // (k-1) - (j+1) + 1
        }
    }
    cout << res;
}

int main()
{
    init();
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    solve();
}
