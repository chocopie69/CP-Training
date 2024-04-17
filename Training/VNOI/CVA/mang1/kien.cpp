#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,k, a[100002];

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i] < 0) a[i] = abs(a[i]);
        else a[i] = k - a[i];
    }
    cout << *max_element(a,a+n);
}


