#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll x;
bool flag;

bool chinhPhuong(ll a)
{
    return sqrt(a) == int(sqrt(a));
}

int main()
{
    cin >> n;
    while(n--)
    {
        flag = false;
        cin >> x;
        if(x % 4 == 2) cout << "impossible" << '\n';
        else if(x % 2 == 0) cout << (x/2+2)/2 << " " << (x/2-2)/2 << '\n';
        else cout << (x+1)/2 << " " << (x-1)/2 << '\n';
    }
}
