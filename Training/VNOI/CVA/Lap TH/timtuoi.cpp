#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t,x,y;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        int a = x-y;
        if(y > a) cout << -1 << '\n';
        else cout << a-y << '\n';
    }
}
