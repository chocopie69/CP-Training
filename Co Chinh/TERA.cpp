#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "TERA"

using namespace std;

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

ll n, x, a[SZ], b[SZ], c[SZ], d[SZ];
vector<ll> v1, v2;

int main()
{
    init();
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            v1.push_back(a[i] + b[j]);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            v2.push_back(c[i] + d[j]);
        }
    }
    sort(all(v1));
    sort(all(v2));
    ll res = 0;
    for(ll k : v1)
    {
        ll pos1 = lower_bound(all(v2), x - k ) - v2.begin();
        if(v2[pos1] != x - k) continue;
        ll pos2 =  upper_bound(all(v2), x - k ) - v2.begin() - 1LL;
        res += max(pos2 - pos1 + 1, 0LL);
    }
    cout << res;
}
