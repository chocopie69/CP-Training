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
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll t,n,a[SZ],x,y, q;
map<ll,ll> mp;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        mp.clear();
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        cin >> q;
        while(q--)
        {
            ll res = 0;
            cin >> x >> y;
            ll cur = sqrt(x * x - y * 4);
            if(cur * cur != x * x - y * 4)
            {
                cout << 0 << ' ';
                continue;
            }
            ll val1 = (cur + x)/2;
            ll val2 = (x - cur)/2;
            if(mp.find(val1) != mp.end() && mp.find(val2) != mp.end())
            {
                if(val1 == val2)
                {
                    res += (mp[val1])*(mp[val2]-1)/2;
                }
                else res += mp[val1]*mp[val2];
            }
            cout << res << ' ';
        }
        cout << '\n';
    }
}
