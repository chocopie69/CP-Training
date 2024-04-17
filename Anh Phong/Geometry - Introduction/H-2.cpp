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
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

struct Coord
{
    ll x,y;
    Coord(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}

    bool operator < (const Coord& other) const
    {
        if(x != other.x) return x < other.x;
        return y < other.y;
    }

    Coord operator - (const Coord& other) const
    {
        return {x - other.x, y - other.y};
    }

    ll operator * (const Coord& other) const
    {
        return x*other.y - y*other.x;
    }
};

int n,m;
vector<Coord> v, hull;
ll area = 0;

bool ccw(Coord x, Coord y, Coord z)
{
    Coord xy = y - x, xz = z - x;
    return xy*xz > 0;
}

ld dist(Coord a, Coord b)
{
    ll distx = a.x - b.x, disty = a.y - b.y;
    return hypot(abs(distx), abs(disty));
}

bool isSegment(Coord a, Coord b, Coord c)
{
    ld dist1 = dist(a, b), dist2 = dist(b, c), dist3 = dist(a,c);
    if(abs(dist3 - (dist1 + dist2)) <= epsilon) return true;
    return false;
}

bool check(Coord c)
{
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        Coord vec1 = hull[i] - c, vec2 = hull[i+1] - c;
        sum += abs(vec1*vec2);
        //if(i == n-1) cout << sum << " " << abs(vec1*vec2) << '\n';
    }
    return sum == area;
}
map<pll, int> mp;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        ll x,y;
        cin >> x >> y;
        if(mp.find({x,y}) != mp.end()) continue;
        mp[ {x,y} ] = 727;
        v.push_back({x,y});
    }
    sort(all(v));
//    for(Coord c : v)
//    {
//        cout << c.x << " and " << c.y << '\n';
//    }
    hull.push_back(v[0]);
    for(int i = 1; i < v.size(); i++)
    {
        while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), v[i]))
        {
            hull.pop_back();
        }
        hull.push_back(v[i]);
    }
    for(int i = v.size()-2; i >= 0; i--)
    {
        while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), v[i]))
        {
            hull.pop_back();
        }
        hull.push_back(v[i]);
    }
    if(v.size() > 1) hull.pop_back();
    n = hull.size();
    hull.push_back(hull[0]);
//    for(Coord c : hull)
//    {
//        cout << c.x << " - " << c.y << '\n';
//    }
    for(int i = 0; i < n; i++)
    {
        area += hull[i] * hull[i+1];
    }
    area = abs(area);
    int res = 0;
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        ll x,y;
        cin >> x >> y;
        if(check({x,y}))
        {
            //cout << x << " " << y << '\n';
            res++;
        }
    }
    cout << res;
}

