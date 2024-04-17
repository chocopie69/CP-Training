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

ll n,x,y,z;

int main()
{
    init();
    cin >> n >> x >> y >> z;
    if(x % 2 == 0)
    {
        cout << n*x - (y-1) << '\n';
    }
    else {
        cout << n*x - (n-y) << '\n';
    }
    ll row = (z-1) / n + 1;
    cout << row << " ";
    z -= n * (row-1);
    if(row % 2 == 0)
    {
        cout << n-z + 1;
    }
    else {
        cout << z;
    }
}

