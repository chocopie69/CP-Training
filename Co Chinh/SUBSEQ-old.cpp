#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e6+2;
int n,k,a[LIMIT],sum[LIMIT],minSum[LIMIT],res=-INT_MAX;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUBSEQ.INP","r",stdin);
    freopen("SUBSEQ.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n >> k;
    sum[0] = 0;
    minSum[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i=1;i<=n;i++)
    {
        minSum[i] = min(minSum[i-1],sum[i]);
    }
    for(int i=k;i<=n;i++)
    {
        res = max(res,sum[i]-minSum[i-k]);
    }
    cout << res;
}
