#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e6+6;
int n,a[MAXN],minNum[MAXN],trace[MAXN],res = -INT_MAX,resi,resj;
int main()
{
    ///freopen("DP_A2.INP","r",stdin);
    ///freopen("DP_A2.OUT","w",stdout);

    cin >> n;
    minNum[0] = INT_MAX/2;
    trace[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        minNum[i] = min(minNum[i-1], a[i]);
        ///if(minNum[i-1] < a[i]) trace[minNum[i]] = trace[minNum[i-1]];
        ///else trace[minNum[i]] = trace[a[i]];
        trace[i] = (a[i] < minNum[i-1] ? i : trace[i-1]);
    }
    for(int i = 2; i <= n; i++)
    {
        if(a[i] - minNum[i-1] > res)
        {
            resj = i;
            resi = trace[i-1];
        }
        res = max(res, a[i] - minNum[i-1]);
    }
    cout << res << '\n' << a[resi] << " " << a[resj];
}
