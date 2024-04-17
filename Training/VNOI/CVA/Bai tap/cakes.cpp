#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

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

ll n,t,x[SZ],a[SZ], res = 0, sum = 0;
priority_queue<ll> pq;

int main()
{
    init();
    cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i] >> a[i];
        pq.push(a[i]);
        sum += a[i];
        while(!pq.empty() && sum + x[i] > t)
        {
            sum -= pq.top();
            pq.pop();
        }
        if(sum + x[i] <= t)
        {
            res = max(1ULL*res, 1ULL*pq.size());
        }
    }
    cout << res;
}

