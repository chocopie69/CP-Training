#include<bits/stdc++.h>
using namespace std;
int n,k,a[100001],f[100001][101];
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i] = a[i]%k;
    }
    for(int j = 1; j <= k-1; j++)
    {
        f[1][j] = INT_MIN;
    }
    for(int i = 0; i <= n; i++)
    {
        f[i][0] = 0;
    }
    f[1][a[1]]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=k-1;j++)
        {
            f[i][j]=max(f[i-1][j],f[i-1][(j-a[i]+k)%k]+1);
        }
    }
    cout<<f[n][0];
}
