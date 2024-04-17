#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int main()
{
    ll y,k,n,x;
    cin >> y >> k >> n;
    bool flag = false;
    for(ll i=1;i<=n-y;i++)
    {
        if((i+y) % k == 0)
        {
            x = i;
            flag = true;
            break;
        }
    }
    for(ll i = x;i<=n-y;i+=k)
    {
        cout << i << " ";
    }
    if(flag == false) cout << -1;
}

