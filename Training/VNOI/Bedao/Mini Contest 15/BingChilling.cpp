#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int t;
ll x,y,a;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> a;
        ll res = a,left=1,right=a;
        while(left <= right)
        {
            ll mid = (left+right)/2;
            ll cur = mid + y*(mid/x);
            if(cur >= a)
            {
                res = min(res,mid);
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        cout << res*5 << endl;
    }
}
