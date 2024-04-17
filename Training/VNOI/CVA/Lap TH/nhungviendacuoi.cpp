#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,res = INT_MAX;

int main()
{
    cin >> n;
    for(int i=1;i*i<=n;i++)
    {
        if(n % i == 0)
        {
            res = min(res,(i+n/i)*2);
        }
    }
    cout << res;
}
