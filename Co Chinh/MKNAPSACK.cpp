#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "MKNAPSACK"

using namespace std;

const int SZ = 6e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


pll a[SZ];
ll n,m, res = 0;
priority_queue<ll> pq;

bool cmp(pll x, pll y)
{
    if(x.first != y.first) return x.first < y.first;
    return x.second > y.second;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        ll w,v;
        cin >> w >> v;
        a[i] = {w,v};
    }
    for(int i = n; i < n+m; i++)
    {
        ll w;
        cin >> w;
        a[i] = {w,0};
    }
    sort(a,a+n+m, cmp);
    for(int i = 0; i < n+m; i++)
    {
        if(a[i].second != 0)
        {
            pq.push(a[i].second);
        }
        else if(!pq.empty())
        {
            res += pq.top();
            //cout << pq.top() << '\n';
            pq.pop();
        }
    }
    cout << res;
}

