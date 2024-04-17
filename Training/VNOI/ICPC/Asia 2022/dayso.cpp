#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 150002,MOD = 998244353;
ll n,a[maxN],sum[maxN],res=0;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

// 1 1 2 2

int main()
{
    init();
    cin >> n;
    n *= 2;
    sum[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        sum[i] = sum[i-1] + a[i];
    }
    for(int i=1;i<=n;i++)
    {
        res += (sum[n]-sum[i]) - (a[i]*(n-i)) + (a[i]*i) - sum[i];
    }
    cout << res;
}
