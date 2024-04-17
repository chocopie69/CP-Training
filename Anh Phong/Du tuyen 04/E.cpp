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

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

struct Rect
{
    ll x, y, val;
    bool operator < (const Rect& other) const
    {
        return x < other.x;
    }
};
Rect a[SZ];
ll n,dp[SZ];
ld getX(int i, int j)
{
    return (ld) (dp[i] - dp[j]) / (a[i].x - a[j].x);
}
deque<int> dq;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].val;
    }
    sort(a + 1, a + n + 1);
    dq.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        while(dq.size() > 1 && getX(dq[0], dq[1]) >= a[i].y) dq.pop_front();
        int j = dq.front();
        dp[i] = max(dp[i-1], a[i].x * a[i].y - a[i].val + dp[j] - a[j].x * a[i].y);
        while(dq.size() > 1 && getX(dq[dq.size()-2], dq.back()) <= getX(dq.back(),i)) dq.pop_back();
        dq.push_back(i);
    }
    cout << dp[n];
}

