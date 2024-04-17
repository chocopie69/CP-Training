#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll y;
string res = "";

ll factorial(ll a)
{
    ll res = 1;
    for(ll i=1;i<=a;i++) res *= i;
    return res;
}

ll findFactorial(ll a)
{
    ll res,cur=1;
    for(res=1;res<=9;res++)
    {
        cur *= res;
        if(cur > a) break;
    }
    return res-1;
}

int main()
{
    cin >> y;
    if(y == 1)
    {
        cout << 0;
        return 0;
    }
    while(y > 0)
    {
        ll fact = findFactorial(y);
        y -= factorial(fact);
        //cout << fact << " " << y << endl;
        res = char(fact+48) + res;
    }
    cout << res;
}
