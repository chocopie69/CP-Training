#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+5;
int n,a[maxN],cnt=0,res = 0;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int maxLength = 1, curLength = 1;
    for(int i=1;i<n;i++)
    {
        if(a[i] > a[i-1])
        {
            curLength++;
            if(i == n-1) maxLength = max(maxLength,curLength);
        } else
        {
            maxLength = max(maxLength,curLength);
            curLength = 1;
        }
    }
    cout << maxLength;
}

