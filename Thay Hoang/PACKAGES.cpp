#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "PACKAGES"

using namespace std;

const int LIMIT = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t,n;
ll a[LIMIT],q;
multiset<ll> ms;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        a[n] = INF;
        ll sum = 0;
        for(int i = 0; i <= n; i++)
        {
            if(!ms.empty() && a[i] + *ms.begin() <= q)
            {
                auto it = ms.upper_bound(q-a[i]);
                it--;
                ll cur = *it;
                ms.erase(it);
                ms.insert(cur+a[i]);
            }
            else
            {
                ms.insert(a[i]);
            }
        }
        cout << ms.size()-1 << '\n';
        while(!ms.empty()) ms.erase(ms.begin());
    }
}

