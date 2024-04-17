#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 1e5+5;
ll n,a[maxN],maxLeft[maxN],maxRight[maxN],res=0;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(i == 0) maxLeft[i] = a[i];
        else maxLeft[i] = max(maxLeft[i-1],a[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(i == n-1) maxRight[i] = a[i];
        else maxRight[i] = max(maxRight[i+1],a[i]);
    }
    for(int j=1;j<n-1;j++)
    {
        res = max(res,2*maxLeft[j-1] - 3*a[j] + 5 * maxRight[j+1]);
    }
    cout << res;
}
