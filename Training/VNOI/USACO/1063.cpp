/// http://www.usaco.org/index.php?page=viewproblem2&cpid=1063

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

int n;
ull res = 0, cnt;
vector<pii> v;

int main()
{
    init();
    cin >> n;
    for(ull i = 1; i <= n; i++)
    {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(all(v));
    for(int i = 1; i <= n; i++)
    {

    }
}
