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

int n,m;

struct Coord
{
    ll x,y;
    Coord(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}

    ll operator * (const Coord& other) const
    {
        return x * other.y - other.x * y;
    }

    Coord operator - (const Coord& other) const
    {
        return {x - other.x, y - other.y};
    }
};

Coord a[SZ], b[SZ];

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    a[n+1] = a[1];
    ll area = 0;
    for(int i = 1; i <= n; i++)
    {
        area += a[i]*a[i+1];
    }
    area = abs(area);
    string res = "YES";
    cin >> m;
    while(m--)
    {
        Coord o;
        cin >> o.x >> o.y;
        ll sum = 0;
        for(int i = 1; i <= n; i++)
        {
            Coord p = a[i] - o, q = a[i+1] - o;
            ll s = abs(p*q);
            if(s == 0)
            {
                res = "NO";
            }
            sum += s;
        }
        if(sum != area) res = "NO";
    }
    cout << res;
}
