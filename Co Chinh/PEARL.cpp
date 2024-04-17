#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "PEARL"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,a[SZ], cnt[SZ], res = 0, x, y;
vector<int> v, nen;
vector<pll> ans;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        nen.push_back(a[i]);
    }
    sort(all(nen));
    nen.erase(unique(all(nen)),nen.end());
    for(int i = 1; i <= n; i++)
    {
        a[i] = (lower_bound(all(nen),a[i]) - nen.begin()) + 1;
    }
    for(int k = 1; k <= n; k++)
    {
        if(n % k != 0) continue;
        res++;
        x = k;
        y = INFLL;
        ll cur = 0;
        for(int i = 1; i <= n; i++)
        {
            if(cnt[a[i]] == 0)
            {
                v.push_back(a[i]);
                cur++;
            }
            cnt[a[i]]++;
            if(i % k == 0)
            {
                y = min(y,cur);
                while(!v.empty())
                {
                    cnt[v.back()] = 0;
                    v.pop_back();
                }
                cur = 0;
            }
        }
        ans.push_back({x,y});
    }
    cout << res << '\n';
    for(pll a : ans)
    {
        cout << a.fi << " " << a.se << '\n';
    }
}
