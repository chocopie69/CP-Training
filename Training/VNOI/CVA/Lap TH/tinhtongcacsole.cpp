#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll a,res=0;

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> a;
        if(abs(a) % 2 == 1) res += a;
    }
    cout << res;
}
