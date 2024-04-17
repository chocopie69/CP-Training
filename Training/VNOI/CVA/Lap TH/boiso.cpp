#include <bits/stdc++.h>
#define ll long long
using namespace std;

int k,m,n;

ll bcnn(ll x,ll y)
{
    return x*y/__gcd(x,y);
}

int main()
{
    cin >> k >> m >> n;
    cout << n/k + n/m - n/bcnn(k,m);
}
