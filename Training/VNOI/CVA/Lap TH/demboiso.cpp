#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll t,n,a=3,b=5;

ll bcnn(ll x,ll y)
{
    return x*y/__gcd(x,y);
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << n/a + n/b - n/bcnn(a,b) << '\n';
    }
}
