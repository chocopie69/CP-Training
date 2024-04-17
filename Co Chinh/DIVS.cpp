#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

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
    cout << n - (n/2 + n/3 + n/5 + n/7) + (n/6 + n/10 + n/14 + n/15 + n/21 + n/35) - (n/(2*3*5) + n/(3*5*7) + n/(2*5*7) + n/(2*3*7)) + n/(2*3*5*7);
}
