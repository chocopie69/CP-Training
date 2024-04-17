#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;

int tichchuso(int x)
{
    int tich = 1;
    while(x > 0)
    {
        tich *= (x % 10);
        x /= 10;
    }
    return tich;
}

int main()
{
    freopen("PERSIST.INP","r",stdin);
    freopen("PERSIST.OUT","w",stdout);
    cin >> n;
    while(n >= 10)
    {
        n = tichchuso(n);
        cnt++;
    }
    cout << cnt;
}
