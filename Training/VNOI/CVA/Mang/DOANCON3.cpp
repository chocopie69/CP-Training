#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+5;
int n,a[maxN],cnt=0,res = 0;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int maxSum = -INT_MAX;
    for(int i=0;i<n;i++)
    {
        int curSum = 0;
        for(int j=i;j<n;j++)
        {
            curSum += a[j];
            maxSum = max(maxSum,curSum);
        }
    }
    cout << maxSum;
}


