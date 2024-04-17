#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "POPUST"

using namespace std;

const int LIMIT = 5e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n, res = 0, minPrice[LIMIT], sum[LIMIT], minNum[LIMIT];
pll a[LIMIT];

bool cmp(pll x, pll y)
{
    return x.second < y.second;
}

void preComputation()
{
    minPrice[n] = a[n].first;
    for(int i = n - 1; i >= 1; i--)
    {
        minPrice[i] = min(minPrice[i+1],a[i].first);
    }
    sum[0] = 0;
    minNum[0] = INT_MAX;
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i].second;
        minNum[i] = min(minNum[i-1],a[i].first - a[i].second);
    }
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
    preComputation();
    for(int i = 1; i < n; i++)
    {
        cout << min(sum[i] + minNum[i], sum[i-1] + minPrice[i+1]) << '\n';
    }
    cout << sum[n] + minNum[n];
}

