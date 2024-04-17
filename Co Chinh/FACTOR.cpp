#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "FACTOR"

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

ll n;

int main()
{
    init();
    cin >> n;
    for(ll i = 2; i * i <= n; i++)
    {
        while(n % i == 0)
        {
            n /= i;
            cout << i << " ";
        }
    }
    if(n != 1) cout << n;
}

