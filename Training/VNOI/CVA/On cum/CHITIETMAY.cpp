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

ll s,k,m, cur, res = 0;

int main()
{
    init();
    cin >> s >> k >> m;
    cur = s/k;
    if(k < m)
    {
        cout << 0;
        return 0;
    }
    while(cur != 0)
    {
        //cout << s << '\n';
        res += cur*(k/m);
        s -= m*(cur*(k/m));
        cur = s/k;
    }
    cout << res;
}

