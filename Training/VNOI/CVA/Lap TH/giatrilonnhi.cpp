#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MN = 1e6+2;
int n,a[MN];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    cout << a[n-2];
}
