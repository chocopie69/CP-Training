#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "ODSUM"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll t,a,b;

ll oddSum(ll n)
{
    if(n % 2 == 0) n--;
    return (1 + n) * ( (n-1)/2+1 ) / 2;
}

ll f(ll n)
{
    if(n <= 1) return n;
    return oddSum(n) + f(n/2);
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        cout << f(b) - f(a-1) << '\n';
    }
}

