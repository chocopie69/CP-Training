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
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t;
ll a,b,c,x,y,g;

void extendedEuclid(ll a, ll b)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        g = a;
    } else
    {
        extendedEuclid(b, a % b);
        ll temp = x;
        x = y;
        y = temp - (a/b)*y;
    }
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        extendedEuclid(a,b);
        if(c % g != 0)
        {
            cout << 0 << '\n';
            continue;
        }
        x *= c/g;
        y *= c/g;
        if(a < 0) x = -x;
        if(b < 0) y = -y;
        cout << x << " " << y << '\n';
    }
}

