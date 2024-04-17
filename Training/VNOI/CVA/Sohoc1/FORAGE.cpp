#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll p,n,k;
    cin >> p >> n >> k;
    ll tien = k*n*(n+1)/2;
    if(p >= tien) cout << "YES";
    else cout << "NO" << '\n' << tien-p;
}
