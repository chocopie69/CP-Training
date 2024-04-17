#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "ROOMALLOCATION"

using namespace std;

const int LIMIT = 5e5+5;
const ll INF = INT_MAX, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll n, res = 1, choose[LIMIT];
pll a[LIMIT];

struct Time
{
    ll time, type, index;
};
vector<Time> v;
set<int> s;

bool cmp(Time x, Time y)
{
    if(x.time != y.time)
        return x.time < y.time;
    return x.type < y.type;
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        ll x,y;
        cin >> x >> y;
        v.push_back({x, 1, i});
        v.push_back({y, 2, i});
        s.insert(i);
    }
    sort(v.begin(),v.end(),cmp);
    for(Time t : v)
    {
        if(t.type == 1)
        {
            choose[t.index] = *(s.begin());
            res = max(res, choose[t.index]);
            s.erase(s.begin());
        }
        else
        {
            s.insert(choose[t.index]);
        }
    }
    cout << res << '\n';
    for(int i = 1; i <= n; i++)
    {
        cout << choose[i] << " ";
    }
}


