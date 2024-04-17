#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

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

ll x, res = 0;
set<ll> s;

int main()
{
    init();
    cin >> x;
    int first;
    for(int i = 41; i >= 0; i--)
    {
        if(x >> i & 1LL)
        {
            first = i;
            break;
        }
    }
    for(int i = first; i >= 0; i--)
    {
        for(int j = i; j >= 0; j--)
        {
            ll cur = (1LL << (i-j+1)) - 1;
            s.insert( (x >> j) & cur );
        }
    }
    for(ll x : s)
    {
        res += x;
    }
    cout << res;
}
