#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NFACTOR"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t;
ll n;

bool check(ll x)
{
    ll tong=0,p=5;
    while(p <= x)
    {
        tong += x/p;
        p *= 5;
    }
    return tong >= n;
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll L = 5, R = 1e17;
        while(L <= R)
        {
            ll mid = (L+R)/2;
            if(check(mid))
            {
                R = mid-1;
            }
            else
            {
                L = mid+1;
            }
        }
        cout << L << '\n';
    }
}

