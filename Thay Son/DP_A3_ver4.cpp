#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+6;
int n,a[MAXN],minNum[MAXN],maxNum[MAXN];
long long res = LLONG_MIN;

int main()
{
    //freopen("DP_A3.INP","r",stdin);
    //freopen("DP_A3.OUT","w",stdout);

    cin >> n;
    maxNum[0] = 0;
    a[0] = INT_MIN;
    
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ///maxNum[i] = max(maxNum[i-1], a[i]);
        if (a[i] > a[maxNum[i-1]]) {
        	maxNum[i] = i;
		}
		else {
			maxNum[i] = maxNum[i-1];
		}
    }


    minNum[n+1] = n+1;
	a[n+1] = INT_MAX;
    for(int i = n; i >= 1; i--)
    {
        ///cin >> a[i];
        ///minNum[i] = min(minNum[i+1], a[i]);
    	if (a[i] < a[minNum[i+1]])
    		minNum[i] = i;
    	else minNum[i] = minNum[i+1];
    }
	    
	    
	/// i < j < k
	int i0, j0, k0;
    for(int j = 2; j <= n-1; j++)
    {
        ///res = max(res, 0LL + maxNum[j-1] + a[j] - minNum[j+1]);
        if (res < 0LL + a[maxNum[j-1]] + a[j] - a[minNum[j+1]]) {
        	res = 0LL + a[maxNum[j-1]] + a[j] - a[minNum[j+1]];
        	i0 = maxNum[j-1];
        	j0 = j;
        	k0 = minNum[j+1];
		}
    }
    cout << res << endl;
    cout << i0 << " " << j0 << " " << k0 << endl;
    cout << a[i0] << " " << a[j0] << " " << a[k0] << endl;
}
