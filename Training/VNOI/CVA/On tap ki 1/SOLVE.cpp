#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

ll tinhChuSo(ll a)
{
    ll res = 0;
    while(a > 0)
    {
        res += a % 10;
        a /= 10;
    }
    return res;
}

int main()
{
    cin >> n;
    ll x = sqrt(n);
    for(ll i = max(x-9*18,1LL); i <= min(x+9*18,n-1); i++)
    {
        if(i*i + i*tinhChuSo(i) == n)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}
