#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 1e3+3;
ll n,a[maxN],res=0;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++)
    {
        ll cur = 1000000000;
        for(int j=i;j>=0;j--)
        {
            cur = min(a[j],cur);
            res = max(res,cur*(i-j+1));
        }
    }
    cout << res;
}
