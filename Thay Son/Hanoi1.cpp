#include <bits/stdc++.h>
using namespace std;

int n,t;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    init();
    cin >> n;
    while(n--)
    {
        cin >> t;
        cout << (t < 60 ? "08:" : "09:");
        t %= 60;
        cout << (t < 10 ? "0" : "") << t << '\n';
    }
}
