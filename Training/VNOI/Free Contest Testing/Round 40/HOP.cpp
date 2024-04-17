#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,k,res;

int main()
{
    cin >> n >> k;
    res = ceil(double(n)/k);
    cout << res;
}
