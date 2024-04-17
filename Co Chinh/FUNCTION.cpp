#include <bits/stdc++.h>
#define ll long double
using namespace std;

ll a,b,c,d;

ll f(ll x)
{
    return a*x*x*x + b*x*x + c*x + d;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("FUNCTION.INP","r",stdin); freopen("FUNCTION.OUT","w",stdout);
}

int main()
{
    init();
    cin >> a >> b >> c >> d;
    ll left = -1e9,right = 1e9,mid,ep = 1e-9;
    while(right - left > ep)
    {
        mid = (left+right)/2;
        ll x = f(left), y = f(mid), z = f(right);
        if(x * y > 0)
        {
            left = mid;
        }
        else right = mid;
    }
    cout << fixed << setprecision(9) << left;
}
