#include <bits/stdc++.h>

#define int long long
using namespace std;
const int MAXN = 1e6+6;
int n,a[MAXN],f1[MAXN],f2[MAXN],f3[MAXN],trace[MAXN],res = -INT_MAX,resi,resj;

int max3(int a, int b, int c) {
    return max(max(a, b), c);
}

signed main()
{
    freopen("DP_A3.INP","r",stdin);
    freopen("DP_A3.OUT","w",stdout);

    cin >> n;
    for(int i = 1;i <= n;++i) cin>>a[i];
    f1[3] = max3(a[1],a[2], a[3]);
    f2[3] = max3(a[1] + a[2], a[2] + a[3], a[1] + a[3]);
    f3[3] = a[1] + a[2] - a[3];

    for(int x = 4; x <= n; x++)
    {
        f1[x] = max(f1[x-1],a[x]);
        f2[x] = max(f2[x-1],f1[x-1] + a[x]);
        f3[x] = max(f3[x-1],f2[x-1] - a[x]);
        ///if(minNum[i-1] < a[i]) trace[minNum[i]] = trace[minNum[i-1]];
        ///else trace[minNum[i]] = trace[a[i]];
        ///trace[i] = (a[i] < minNum[i-1] ? i : trace[i-1]);
    }
    cout << f3[n];
}
