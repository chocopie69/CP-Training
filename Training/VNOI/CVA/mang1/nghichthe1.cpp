#include <bits/stdc++.h>
using namespace std;

const int MN = 102;
int n,a[MN];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        int cnt = 0;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j] > a[i])
                cnt++;
        }
        cout << cnt << " ";
    }
}
