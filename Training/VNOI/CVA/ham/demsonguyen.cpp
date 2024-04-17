#include <bits/stdc++.h>
using namespace std;

long long a,b,c,d;


long long calc(long long x)
{
    return b/x - (a-1)/x;
}

int main()
{
    cin >> a >> b >> c >> d;
    cout << b-a+1-calc(c)-calc(d)+calc(c*d/__gcd(c,d));
}
