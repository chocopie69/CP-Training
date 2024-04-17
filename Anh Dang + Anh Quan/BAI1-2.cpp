#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BAI1"

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
ll n;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n < 6)
        {
            cout << 0 << '\n';
            continue;
        }
        ll mul = 1;
        for(ll i = 1; i <= 1e6+3; i++)
        {
            if(i > 3) mul /= (i-3);
            if( (double) mul > (double) n / i)
            {
                cout << mul*(i-3) << '\n';
                break;
            }
            mul *= i;
        }
    }
}
