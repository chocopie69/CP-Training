#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "LAS2"

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

ll n,a[SZ], res = 1;
map<pll,ll> mp;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        mp[ {a[i],INFLL } ]++;
        for(int j = 1; j < i; j++)
        {
            ll d = a[i] - a[j];
            mp[ {a[i], d } ] = max(mp[ {a[j],d } ], mp[ {a[j],INFLL } ] ) + 1;
            res = max(res,  mp[ {a[i], d } ]);
            //cout << i << " " << j << " " << d << " " << mp[ { a[i],d } ] << '\n';
        }
    }
    cout << res;
}
