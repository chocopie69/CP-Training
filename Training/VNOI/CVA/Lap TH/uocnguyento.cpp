#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,res=2;

int main()
{
    cin >> n;
    for(ll i=2;i*i<=n;i++)
    {
        while(n % i == 0)
        {
            n /= i;
            res = max(res,i);
        }
    }
    if(n != 1) res = max(res,n);
    cout << res;
}


