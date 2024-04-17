#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "PERSIST"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;

int tcs(int x)
{
    int tich = 1;
    while(x > 0)
    {
        tich *= (x % 10);
        x /= 10;
    }
    return tich;
}

int res(int x)
{
    if(x < 10) return 0;
    return res(tcs(x)) + 1;
}

int main()
{
    init();
    cin >> n;
    cout << res(n);
}

