#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "H"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,res = 0, cur = 0;
pll a[SZ];

bool cmp(pll x, pll y)
{
    if(x.second == y.second) return x.first < y.first;
    return x.second > y.second;
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1,a+n+1,cmp);
    res = a[1].first*a[1].second;
    cur = a[1].first;
    for(int i = 2; i <= n; i++)
    {
        if(a[i].first > cur)
        {
            res += (a[i].first - cur)*a[i].second;
            cur = a[i].first;
        }
    }
    cout << res;
}


