#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e5+2;
ll n,a[LIMIT];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=n-2;i>=0;i--)
    {
        a[i] += (a[i+1]/2);
    }
    cout << a[0];
}
