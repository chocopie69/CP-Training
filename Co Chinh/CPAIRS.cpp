#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CPAIRS"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m, res = 0;
map<int,int> mp1, mp2;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp1[x]++;
    }
    for(int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        mp2[x]++;
    }
    for(pii p : mp1)
    {
        res += min(p.se, mp2[p.fi]);
    }
    cout << res;
}
