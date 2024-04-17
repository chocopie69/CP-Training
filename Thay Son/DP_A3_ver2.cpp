#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+6;
int n,a[MAXN],minNum[MAXN],maxNum[MAXN];
long long res = LLONG_MIN;

int main()
{
    freopen("DP_A3.INP","r",stdin);
    freopen("DP_A3.OUT","w",stdout);

    cin >> n;
    maxNum[0] = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxNum[i] = max(maxNum[i-1], a[i]);
    }


    minNum[n+1] = INT_MAX;
    for(int i = n; i >= 1; i--)
    {
        ///cin >> a[i];
        minNum[i] = min(minNum[i+1], a[i]);
    }
	    
	    
	/// i < j < k
    for(int j = 2; j <= n-1; j++)
    {
        res = max(res, 0LL + maxNum[j-1] + a[j] - minNum[j+1]);
    }
    cout << res;
}
