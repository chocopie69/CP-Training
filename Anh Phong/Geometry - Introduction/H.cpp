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

int n,m, l = 1, r = n - 2;
vector<Coord> v, hull;

bool ccw(Coord x, Coord y, Coord z)
{
    Coord xy = y - x, xz = z - x;
    return xy*xz > 0;
}

ll dist(Coord a, Coord b)
{
    ll distx = a.x - b.x, disty = a.y - b.y;
    return distx*distx + disty*disty;
}

bool isSegment(Coord a, Coord b, Coord c)
{
    ll dist1 = dist(a, b), dist2 = dist(b, c), dist3 = dist(a,c);
    Coord ab = b - a, ac = c - a;
    if(ab*ac == 0 && dist1 <= dist3 && dist2 <= dist3) return true;
    return false;
}

bool check(Coord c)
{
    Coord p = c - hull[0];
//    int lo = 1, hi = n-2, mid, pos;
//    while(lo <= n-2 && isSegment(hull[0], hull[1], hull[lo+1])) lo++;
//    while(hi > 1 && isSegment(hull[0], hull[n-1], hull[hi])) hi--;
    int lo = l, hi = r, mid, pos;
    bool flag = false;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        Coord cur1 = hull[mid], cur2 = hull[mid+1], vec1 = cur1 - hull[0], vec2 = cur2 - hull[0];
        if(vec1*p <= 0 && vec2*p > 0)
        {
            pos = mid;
            flag = true;
            break;
        } else if(vec2*p <= 0)
        {
            lo = mid+1;
        } else if(vec1*p > 0)
        {
            hi = mid-1;
        }
    }
    if(flag)
    {
        Coord vec1 = hull[pos+1] - hull[pos], vec2 = c - hull[pos], vec3 = hull[0] - hull[pos];
        //cout << "found " << pos << '\n';
        if((vec1*vec2) * (vec1*vec3) >= 0) return true;
    }
    if(isSegment(hull[0], c, hull[l]))
    {
        //cout << "wtf1 " << pos << '\n';
        return true;
    }
    if(isSegment(hull[0], c, hull[r+1]))
    {
        //cout << "wtf2 " << hull[0].x << " " << hull[0].y << " " << c.x << " " << c.y << " " << hull[n-1].x << " " << hull[n-1].y << '\n';
        return true;
    }
    return false;
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
//    cout << '\n';
//    for(Coord c : hull) cout << c.x << " " << c.y << '\n';
//    cout << '\n';
    int res = 0;
    l = 1;
    r = n-2;
    while(l <= n-2 && isSegment(hull[0], hull[1], hull[l+1])) l++;
    while(r > 1 && isSegment(hull[0], hull[n-1], hull[r])) r--;
    //cout << l << " " << r << '\n';
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
//    Coord g = {2,2};
//    Coord p = g - hull[0], cur1 = hull[2], cur2 = hull[3], vec1 = cur1 - hull[0], vec2 = cur2 - hull[0];
//    cout << vec1*p << " " << vec2*p;
}
