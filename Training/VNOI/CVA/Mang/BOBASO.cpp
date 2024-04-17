#include <bits/stdc++.h>
using namespace std;

const int maxN = 1002;
int n,a[maxN],cnt=0,res = 0;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(a[i] + a[j] > a[k])
                {
                    cnt++;
                    res = max(res,a[i] + a[j] + a[k]);
                }
            }
        }
    }
    cout << cnt << " " << res;
}
