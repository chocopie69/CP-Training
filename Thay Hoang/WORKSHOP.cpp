#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "WORKSHOP"

using namespace std;

const int LIMIT = 8e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n, res = 0, sum = 0;
vector<pll> a;

bool cmp(pll x, pll y)
{
    return x.first - x.second < y.first - y.second;
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= 2 * n; i++)
    {
        ll x,y;
        cin >> x >> y;
        res += y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end(), cmp);
    for(int i = 0; i < n; i++)
    {
        res = a[i].first + (res - a[i].second);
    }
    cout << res;
}


