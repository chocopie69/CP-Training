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

struct Segment
{
    int lo, hi;
    Segment(int _lo = 0, int _hi = 0) : lo(_lo), hi(_hi) {}

    bool operator < (const Segment& other) const
    {
        return hi < other.hi;
    }
};

int n,m,k;
vector<Segment> segments;

struct Point
{
    int pos, prev, id;
    Point(int _pos = 0, int _prev = 0, int _id = 0) : pos(_pos), prev(_prev), id(_id) {}
    bool operator < (const Point& other) const
    {
        return pos < other.pos;
    }
};

vector<Point> points;

int res[SZ];

int seg[4*SZ], pos;

void updateR(int id, int lo, int hi)
{
    if(lo == hi)
    {
        seg[id]++;
        return;
    }
    int mid = (lo + hi) / 2;
    if(pos <= mid)
    {
        updateR(2*id, lo, mid);
    } else updateR(2*id+1, mid+1, hi);
    seg[id] = seg[2*id] + seg[2*id+1];
}

void update(int pos)
{
    ::pos = pos;
    updateR(1,1,n);
}

int u,v;

int queryR(int id, int lo, int hi)
{
    if(lo > v || hi < u) return 0;
    if(lo >= u && hi <= v) return seg[id];
    int mid = (lo + hi) / 2;
    return queryR(2*id, lo, mid) + queryR(2*id+1, mid+1, hi);
}

int query(int u, int v)
{
    ::u = u;
    ::v = v;
    return queryR(1, 1, n);
}

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
    {
        int lo,hi;
        cin >> lo >> hi;
        segments.push_back({lo, hi});
    }
    sort(all(segments));
    for(int i = 1; i <= k; i++)
    {
        int t;
        cin >> t;
        int prev = 0, pos;
        vector<int> tmp;
        for(int j = 1; j <= t; j++)
        {
            cin >> pos;
            tmp.push_back(pos);
        }
        sort(all(tmp));
        for(int pos : tmp)
        {
            points.push_back({pos, prev, i});
            prev = pos;
        }
        points.push_back({n+1, prev, i});
    }
    sort(all(points));
    int i = 0;
    for(Point p : points)
    {
        int pos = p.pos, prev = p.prev, id = p.id;
        while(i < m && segments[i].hi < pos)
        {
            update(segments[i].lo);
            i++;
        }
        res[id] += query(prev + 1, pos - 1);
    }
    for(int i = 1; i <= k; i++)
    {
        cout << res[i] << '\n';
    }
}
