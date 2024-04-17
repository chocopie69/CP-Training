#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll g,l,res = 1e18+5,a,b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> g >> l;
    bool flag = false;
    for(ll i=g;i<=g*l;i+=g)
    {
        if((g*l) % i == 0 && __gcd(i,g*l/i) == g)
        {
            if(i+g*l/i < res)
                a = i,b = g*l/i;
            res = min(res,i+g*l/i);
            flag = true;
        }
    }
    if(flag == false) cout << -1;
    else cout << res;
}
