#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<long long, long long>
using namespace std;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("XD.inp", "r",stdin);
    //freopen("XD.out","w",stdout);
}

ll k;
vector<pll> res;

int main()
{
    ll n;
    cin >> n;
    for(ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            k++;
            int cnt = 0;
            while(n % i == 0)
            {
                n /= i;
                cnt++;
            }
            res.push_back({i, cnt});
        }
    }
    if(n > 1)
    {
        k++;
        res.push_back({n,1});
    }
    cout << k << '\n';
    for(pll x : res)
    {
        cout << x.fi << ' ' << x.se << '\n';
    }
}
