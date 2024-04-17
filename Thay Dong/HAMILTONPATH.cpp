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

const int SZ = 1e6+5, BSIZE = 1e3;
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
    int id;
    Coord(ll _x = 0, ll _y = 0, int _id = 0) : x(_x), y(_y), id(_id) {}

    bool operator < (const Coord& other) const
    {
        return y < other.y;
    }
};

vector<Coord> vec[SZ];
int n;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        ll x,y;
        cin >> x >> y;
        vec[x / BSIZE].push_back({x,y,i});
    }
    for(int i = 0; i <= BSIZE; i++)
    {
        if(vec[i].empty()) continue;
        sort(all(vec[i]));
        if(i % 2 == 0)
        {
            for(int j = 0; j < vec[i].size(); j++) cout << vec[i][j].id << " ";
        } else
        {
            for(int j = vec[i].size() - 1; j >= 0; j--) cout << vec[i][j].id << " ";
        }
    }
}
