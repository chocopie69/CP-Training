#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "PARITY"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int t;
ll n;

bool recur(ll n, ll cnt)
{
    if(n == 0)
        return (cnt == 0);
    if(n % 2 == 0)
        return recur(n / 2, cnt + 1);
    else
        return recur(n / 2, cnt - 1);
}


int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << recur(n,0) << '\n';
    }
}

