#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,res=1e15;

int main()
{
    cin >> n;
    for(ll i=1;i*i <= n;i++)
    {
        if(n % i == 0)
        {
            res = min(res,i-1 + (n/i)-1);
        }
    }
    cout << res;
}

