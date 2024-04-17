#include <bits/stdc++.h>
#define ll long long
#define ld long double
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
const double epsilon = 1e-3, PI = acos(-1);

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

struct Coord
{
    ll x,y;
    Coord(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}

    Coord operator - (const Coord& other) const
    {
        return {other.x - x, other.y - y};
    }

    ll operator * (const Coord& other) const
    {
        return x * other.y - y * other.x;
    }

    bool operator < (const Coord& other) const
    {
        if(x != other.x) return x < other.x;
        return y < other.y;
    }
};

int n, r;
Coord a[SZ];
vector<Coord> hull;

bool ccw(Coord x, Coord y, Coord z)
{
    Coord xy = y-x, xz = z - x;
    return xy * xz > 0;
}

ld dist(Coord x, Coord y)
{
    Coord xy = y - x;
    return hypot((ld) abs(xy.x), (ld) abs(xy.y));
}

int main()
{
    init();
    cin >> n >> r;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + n + 1);
    hull.push_back(a[1]);
    for(int i = 2; i <= n; i++)
    {
        while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), a[i]))
        {
            hull.pop_back();
        }
        hull.push_back(a[i]);
    }
    for(int i = n-1; i >= 1; i--)
    {
        while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), a[i]))
        {
            hull.pop_back();
        }
        hull.push_back(a[i]);
    }
    if(n > 1) hull.pop_back();
    hull.push_back(hull[0]);
    ld p = 0;
    for(int i = 0; i < hull.size()-1; i++)
    {
        p += dist(hull[i], hull[i+1]);
    }
    cout << fixed << setprecision(4) << p + PI*2*r;
}

