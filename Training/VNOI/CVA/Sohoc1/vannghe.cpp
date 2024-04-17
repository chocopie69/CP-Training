#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int ucln = __gcd(n,m);
    cout << ucln << '\n' << n/ucln << " " << m/ucln;
}
