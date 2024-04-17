#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a,b, res = 1,cnt=0;
map<ll,ll> m;

void phantichNT(ll h)
{
    ll x = h;
    for(ll i = 2;i*i <= x;i++)
    {
        while(x % i == 0)
        {
            m[i]++;
            x /= i;
        }
    }
    if(x != 1) m[x]++;
}

int main()
{
    freopen("uocso.inp","r",stdin);
    freopen("uocso.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        m.clear();
        res = 1;
        cin >> a >> b;
        phantichNT(a);
        phantichNT(b);
        for(auto it=m.begin();it != m.end();it++)
        {
            res *= (it->second+1);
        }
        cout << res << '\n';
    }
}
