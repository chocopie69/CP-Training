#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "FRIENDS"

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

struct Coord
{
    int x,y, id;
    Coord(int _x = 0, int _y = 0, int _id = 0)
    {
        x = _x;
        y = _y;
        id = _id;
    }
    Coord operator - (const Coord& other) const
    {
        return {other.x-x,other.y-y,0};
    }
    bool operator != (const Coord& other) const
    {
        return abs((double)y/x - (double)other.y/x) > epsilon;
    }
    bool operator < (const Coord& other) const
    {
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
};

int n;
Coord a[SZ];
vector<Coord> v;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    if(n == 2)
    {
        cout << 1 << '\n' << "1 2";
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i = 1; i < n; i++)
    {
        v.push_back(a[i+1]-a[i]);
    }
    bool flag = true;
    for(int i = 0; i < v.size()-1; i++)
    {
        if(v[i] != v[i+1]) flag = false;
    }
    if(flag)
    {
        cout << 1 << '\n' << a[1].id << " " << a[n].id;
    } else
    {
        cout << 0;
    }
}
