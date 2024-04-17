#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "DONGXU"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

ll n,m;
map<ll,ll> dif;
vector<pll> pos;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        ll x,y;
        cin >> x >> y;
        if(x <= y)
        {
            dif[x]++;
            dif[y+1]--;
//            pos.push_back(x);
//            pos.push_back(y+1);
        } else
        {
            dif[x]++;
            dif[n+1]--;
            dif[1]++;
            dif[y+1]--;
//            pos.push_back(x);
//            pos.push_back(n+1);
//            pos.push_back(1);
//            pos.push_back(y+1);
        }
    }
//    sort(all(pos));
//    pos.erase(unique(all(pos)), pos.end());
    for(pll p : dif)
    {
        pos.push_back({p.fi,p.se});
    }
    ll res = pos[0].se, cur = 0, prev, cnt = 0;
    for(int i = 1; i < pos.size(); i++)
    {
        pos[i].se += pos[i-1].se;
        res = max(res, pos[i].se);
    }
    cout << res << " ";
    for(int i = 0; i < pos.size(); i++)
    {
        if(pos[i].se == res) cnt += pos[i+1].fi - pos[i].fi;
    }
    cout << cnt;
}
