#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, res = 1,cnt=0;

bool prime(ll x)
{
    if(x < 2) return false;
    for(int i=2;i<=sqrt(x);i++) if(x % i == 0) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(ll i=1e13;i<=1e14;i++) if(prime(i)) {
        cout << i;
        return 0;
    }
}

