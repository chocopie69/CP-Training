#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 2*1e5+5,N = 1e5;
int n,m,a[LIMIT],b[LIMIT],cnta[LIMIT],cntb[LIMIT],res1=0,res2=0;

void solve()
{
    memset(cnta,0,sizeof(cnta));
    memset(cntb,0,sizeof(cntb));
    for(int i=0;i<n;i++)
    {
        cnta[a[i]+N]++;
    }
    for(int i=0;i<m;i++)
    {
        cntb[b[i]+N]++;
    }
    for(int i=0;i<LIMIT;i++)
    {
        if(cnta[i] > 0 || cntb[i] > 0)
        {
            res1++;
            if(cnta[i] > 0 && cntb[i] > 0) res2++;
        }
    }
    cout << res1 << " " << res2;
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    solve();
}
