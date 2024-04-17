#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    if(k > min(n,m)) cout << n+m+k;
    else
    {
        for(int i=1;i<=k;i++)
        {
            cout << i << " " << i << '\n';
        }
    }
}
