#include <bits/stdc++.h>
using namespace std;

int n,s;
string res;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MINNUM.INP","r",stdin);
    freopen("MINNUM.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n >> s;
    for(int i=1;i<=n;i++)
    {
        if(s > 9)
        {
            res = "9" + res;
            s -= 9;
        }
        else
        {
            int digit = s - (i != n);
            res = char(digit+48) + res;
            s -= digit;
        }
    }
    cout << res;
}
