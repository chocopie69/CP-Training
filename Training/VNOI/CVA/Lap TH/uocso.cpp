#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,res=1;

int main()
{
    cin >> n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n % i == 0)
        {
            int cnt=0;
            while(n % i == 0)
            {
                n /= i;
                cnt++;
            }
            res *= (cnt+1);
        }
    }
    if(n != 1) res*=2;
    cout << res;
}



