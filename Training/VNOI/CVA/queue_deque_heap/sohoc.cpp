#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

bool isPrime(ll x)
{
    if(x < 2) return false;
    for(ll i=2;i*i <= x;i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}

int main()
{
    cin >> n;
    ll sqrtn = sqrt(n);
    while(true)
    {
        sqrtn++;
        if(isPrime(sqrtn))
        {
            cout << sqrtn*sqrtn;
            return 0;
        }
    }
}
