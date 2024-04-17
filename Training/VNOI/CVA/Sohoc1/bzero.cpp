#include <bits/stdc++.h>
using namespace std;

int cntZero(int x,int y)
{
    int p = y,res=0;
    while(p <= x)
    {
        res += x/p;
        p *= y;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << min(cntZero(n,2),cntZero(n,5));
}
