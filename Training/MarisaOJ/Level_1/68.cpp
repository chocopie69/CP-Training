#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

struct Coord
{
    int x, y, z;

    bool operator < (const Coord& other) const
    {
        if(x != other.x) return x < other.x;
        if(y != other.y) return y < other.y;
        return z < other.z;
    }
};

int n;
vector<Coord> v;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        v.pb({x,y,z});
    }
    sort(all(v));
    for(Coord c : v)
    {
        cout << c.x << " " << c.y << " " << c.z << '\n';
    }
}

