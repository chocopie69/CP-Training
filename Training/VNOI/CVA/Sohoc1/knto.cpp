#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, res = 1,cnt=0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll i = 2,cur=0;
    for(ll i=2;i*i<=n;i++)
    {
        if(n % i == 0) {
            cnt++;
            while(n % i == 0)
            {
                cur++;
                n /= i;
            }
            res*= (cur+1);
        }
        cur = 0;
    }
    if(n != 1) {
        res *= 2;
        cnt++;
    }
    cout << res-cnt;
}
