#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,q;

ll w[SZ], res[SZ], sum[SZ];
pll queries[SZ];

deque<int> dq1, dq2;

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    sort(w + 1, w + n + 1);
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + w[i];
    }
    for(int i = 1; i <= q; i++)
    {
        cin >> queries[i].fi;
        queries[i].se = i;
    }
    sort(queries + 1, queries + q + 1);
    for(int i = 1; i <= n; i++)
    {
        if(w[i] + queries[1].fi <= 0) dq1.push_back(i);
        else dq2.push_back(i);
    }
    for(int i = 1; i <= q; i++)
    {
        ll t = queries[i].fi, id = queries[i].se;
        while( !dq1.empty() && w[dq1.back()] + t > 0 )
        {
            dq2.push_front(dq1.back());
            dq1.pop_back();
        }
        //cout << t << ' ' << id << '\n';
        if(dq1.empty())
        {
            res[id] = (w[1] + t) * (sum[n] - sum[1] + t * (n-1) ) - t*t*(n-1);
        } else if(dq2.empty())
        {
            res[id] = (w[n] + t) * (sum[n-1] + t * (n-1) ) - t*t*(n-1);
        } else
        {
            //cout << ( sum[n] - sum[dq2.front() - 1] + t * (n - dq2.front() + 1) ) << " ";
            res[id] = (w[1] + t) * ( sum[n] - sum[dq2.front() - 1] + t * (n - dq2.front() + 1) ) + (w[n] + t) * (sum[dq1.back()] + t * dq1.back() ) - (w[1] + t) * (w[n] + t) - t*t*(n-1);
            //cout << (w[1] + t) * ( sum[n] - sum[dq2.front() - 1] + t * (n - dq2.front() + 1) ) << " " << (w[n] + t) * (sum[dq1.back()] + t * dq1.back() ) << " " << (w[1] + t) * (w[n] + t) << ' ' << t*t*(n-1) << ' ' << id << '\n';
        }
    }
    for(int i = 1; i <= q; i++)
    {
        cout << res[i] << " ";
    }
}
