#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NOPASS"

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

ll n,a[SZ],b[SZ],pos[SZ], res = 0;
ll st[30][SZ];

void rmq()
{
    for (ll i = 1; i <= n; ++i) st[0][i] = b[i];
    for (ll j = 1; (1 << j) <= n; ++j)
        for (ll i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}

ll getMin(ll l, ll r)
{
    ll k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b[i] = pos[b[i]];
        //cout << b[i] << " ";
    }
    rmq();
    for(int i = 1; i < n; i++)
    {
        if(getMin(i+1,n) < b[i]) res++;
    }
    cout << res;
}
