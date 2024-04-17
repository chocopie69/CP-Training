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

int n,m, res = 0;
pii a[LIMIT];

bool cmp(pii x, pii y)
{
    return x.second - x.first < y.second - y.first;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].second;
    }
    sort(a,a+n,cmp);
    res = m;
    for(int i = 0; i < n; i++)
    {
        if(a[i].first + m < a[i].second) break;
        m -= (a[i].second - a[i].first);
        m += a[i].second;
        res = max(res,m);
    }
    cout << res;
}

