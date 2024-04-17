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

ll c1, c2, n, m;
bool bought[SZ];

struct Coord
{
    ll pos, val, id;
    Coord(ll _pos = 0, ll _val = 0, ll _id = 0) : pos(_pos), val(_val), id(_id) {}

    bool operator < (const Coord& other) const
    {
        if(pos != other.pos) return pos < other.pos;
        return val > other.val;
    }
};

vector<Coord> coords;

int main()
{
    init();
    cin >> c1 >> c2 >> n;
    for(int i = 1; i <= n; i++)
    {
        ll x,y;
        cin >> x >> y;
        coords.push_back({y,x, 0});
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        ll u,v;
        cin >> u >> v;
        coords.push_back({ u, -c1, i });
        coords.push_back({ v, -c2, i });
    }
    sort(all(coords));
    ll cur = 0, res = 0;
    for(Coord c : coords)
    {
        ll pos = c.pos, val = c.val, id = c.id;
        if(val > 0) cur += val;
        else
        {
            if(cur + val >= 0 && !bought[id])
            {
                bought[id] = true;
                cur += val;
                res++;
            }
        }
    }
    cout << res;
}
