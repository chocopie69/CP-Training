#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin >> n >> q;
    int a[n],maxNum = -INT_MAX,minNum = INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i] > maxNum) maxNum = a[i];
        if(a[i] < minNum) minNum = a[i];
    }
    int x;
    while(q--)
    {
        cin >> x;
        if(x >= minNum && x <= maxNum) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
