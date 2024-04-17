#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int maxN = 105;
ll a[maxN];
int n;

ll bcnn(ll x,ll y)
{
    return x*y/__gcd(x,y);
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    ll res = a[0];
    for(int i=1;i<n;i++) res = bcnn(res,a[i]);
    cout << res << endl;
    for(int i=0;i<n;i++) cout << res/a[i] << " ";
}
