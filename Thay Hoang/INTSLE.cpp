#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "INTEQN"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t;
ll a1,b1,c1,x1,y1,g1,a2,b2,c2,x2,y2,g2, res1, res2, cnt = 0, x, y;
map<pll,ll> mp;

void extendedEuclid(ll a, ll b)
{
    if(b == 0)
    {
        x2 = 1;
        y2 = 0;
        g2 = a;
    } else
    {
        extendedEuclid(b, a % b);
        ll temp = x2;
        x2 = y2;
        y2 = temp - (a/b)*y2;
    }
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        mp.clear();
        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        extendedEuclid(a1,b1);
        x1 = x2;
        y1 = y2;
        g1 = g2;
        if(c1 % g1 != 0)
        {
            cout << "NO SOLUTION" << '\n';
            continue;
        }
        extendedEuclid(a2,b2);
        if(c2 % g2 != 0)
        {
            cout << "NO SOLUTION" << '\n';
            continue;
        }
        for(ll k = -1e6; k <= 1e6; k++)
        {
            mp[{x1 + k * (b1/g1), y1 - k * (a1/g1)}]++;
        }
        for(ll k = -1e6; k <= 1e6; k++)
        {
            if(mp[{x1 + k * (b1/g1), y1 - k * (a1/g1)}] > 0);
        }
    }
}


