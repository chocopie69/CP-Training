#include <bits/stdc++.h>
using namespace std;
const int MN = 102;
int a[MN],p[MN],n,j;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin >>p [i];
    for(int i=n;i>=1;i--)
    {
        for(j=n;j>=1;j--)
        {
            if(p[j] == 0) break;
        }
        a[j]=i;
        for(int k=j;k<=n;k++)
        {
            p[k]--;
        }
    }
    for(int i=1;i<=n;i++) cout << a[i] <<" ";
}
