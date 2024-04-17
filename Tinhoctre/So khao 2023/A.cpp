#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,q,h[SZ],L,R,a[SZ];
vector<pll> queries;

namespace sub1
{
    void solve()
    {
        for(pll q : queries)
        {
            int cnt = 0;
            ll sum = 0;
            L = q.fi;
            R = q.se;
            for(int i = 1; i <= n; i++)
            {
                if(h[i] >= L && h[i] <= R)
                {
                    cnt++;
                    a[cnt] = h[i];
                }
            }
            for(int i = 1; i < cnt; i++)
            {
                sum += abs(a[i]-a[i+1]);
            }
            cout << sum << '\n';
        }
    }
};

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    while(q--)
    {
        cin >> L >> R;
        queries.push_back({L,R});
    }
    if(n <= 5005 && q <= 5005)
        sub1::solve();
}

