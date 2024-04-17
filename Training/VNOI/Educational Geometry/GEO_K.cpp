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

struct Coord
{
    ll x, y;
    Coord(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}

    Coord operator - (const Coord& other) const
    {
        return {x - other.x, y - other.y};
    }

    ll operator * (const Coord& other) const
    {
        return x * other.y - y * other.x;
    }

    ll operator % (const Coord& other) const
    {
        return x * other.x + y * other.y;
    }
};

Coord a,b;

int main()
{
    init();
    cin >> a.x >> a.y >> b.x >> b.y;
    Coord ba = a-b;
    cout << fixed << setprecision(7) << hypot(ba.x, ba.y);
}
