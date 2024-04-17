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

int n;
Coord a[SZ];
vector<Coord> hull;

ll ccw(Coord x, Coord y, Coord z)
{
    Coord xy = y-x, xz = z - x;
    return xy * xz;
}

ld dist(Coord x, Coord y)
{
    Coord xy = y - x;
    return hypot((ld) abs(xy.x), (ld) abs(xy.y));
}

ll s(Coord x, Coord y, Coord z)
{
    return abs(ccw(x, y, z));
}

ll res = 0;

int main()
{
    init();
    cout << fixed << setprecision(2);
    while(cin >> n)
    {
        if(n == -1) break;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i].x >> a[i].y;
        }
        sort(a + 1, a + n + 1);
        hull.clear();
        hull.push_back(a[1]);
        for(int i = 2; i <= n; i++)
        {
            while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), a[i]) > 0)
            {
                hull.pop_back();
            }
            hull.push_back(a[i]);
        }
        for(int i = n-1; i >= 1; i--)
        {
            while(hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), a[i]) > 0)
            {
                hull.pop_back();
            }
            hull.push_back(a[i]);
        }
        if(n > 1) hull.pop_back();
        n = hull.size();
        for(int i = 0; i < n; i++) hull.push_back(hull[i]);
        for(int i = 0; i < n; i++)
        {
            int k = i+2;
            for(int j = i+1; j < i + n; j++)
            {
                while(k < i + n && s(hull[i], hull[j], hull[k]) <= s(hull[i], hull[j], hull[k+1])) k++;
                res = max(res, s(hull[i], hull[j], hull[k]));
            }
        }
        cout << (double) res / 2 << '\n';
        res = 0;
    }
}
