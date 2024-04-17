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
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Query
{
    int lo, hi;
    ll x;
    Query(int _lo = 0, int _hi = 0, ll _x = 0)
    {
        lo = _lo;
        hi = _hi;
        x = _x;
    }
};

int n,q;

vector<Query> queries;

int main()
{
    init();
    cin >> n >> q;
    while(q--)
    {
        int type,lo,hi;
        cin >> type >> lo >> hi;
        if(type == 1)
        {
            ll x;
            cin >> x;
            queries.push_back({lo, hi, x});
        } else
        {
            ll res = 0;
            while(!queries.empty())
            {
                Query cur = queries.back();
                queries.pop_back();
                int curlo = max(lo,cur.lo), curhi = min(hi, cur.hi);
                if(curlo <= curhi && (curhi - curlo + 1) % 2 == 1) res ^= cur.x;
            }
            cout << res << '\n';
        }
    }
}
