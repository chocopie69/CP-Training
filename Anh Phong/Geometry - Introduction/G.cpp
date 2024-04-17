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

int n;

struct Coord
{
    ll x,y;
    Coord(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}

    bool operator < (const Coord& other) const
    {
        ld a = (long double) atan2(y,x), b = (long double) atan2(other.y, other.x)
        return (long double) atan2(y,x) < (long double) atan2(other.y, other.x);
    }
};

Coord a[SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        cout << a[i].x << " " << a[i].y << " " << (long double) atan2(a[i].y, a[i].x) << '\n';
    }
    cout << a[1].x << " " << a[1].y << " " << a[ n/2 + 1 ].x << " " << a[ n/2 + 1 ].y;
}

/*
4
0 0
1 0
0 1
1 1
*/
