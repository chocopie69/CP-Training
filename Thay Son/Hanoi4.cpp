#include <bits/stdc++.h>
#define ll long long
#define pll pair<long long,long long>
using namespace std;

const int MAXN = 5e5+5;
ll n,sum[MAXN],minSum[MAXN],res=0;
pll a[MAXN];

bool cmp(pll x, pll y)
{
    return x.first < y.first;
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1,a+n+1,cmp);
    sum[0] = 0;
    minSum[0] = 0;
    for(int i=1;i<=n;i++)
    {
        sum[i] = sum[i-1] + a[i].second;
        minSum[i] = min(minSum[i-1],sum[i-1] - a[i].first);
    }
    for(int j=1;j<=n;j++)
    {
        res = max(res,sum[j]- a[j].first - minSum[j]);
        //cout << sum[j] << " " << a[j].first << " " << minSum[j] << endl;
    }
    cout << res;
}
