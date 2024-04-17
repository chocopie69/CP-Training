#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+6;
int n,a[MAXN],minNum[MAXN],res = -INT_MAX;

int main()
{
    freopen("DP_A2.INP","r",stdin);
    freopen("DP_A2.OUT","w",stdout);

    cin >> n;
    minNum[0] = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        minNum[i] = min(minNum[i-1], a[i]);
    }
    for(int i = 2; i <= n; i++)
    {
        res = max(res, a[i] - minNum[i-1]);
    }
    cout << res;
}
