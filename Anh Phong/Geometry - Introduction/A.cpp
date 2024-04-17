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
ll a,b,c, cnt1 = 0, cnt2 = 0, res = 0, x, y;
pll p[SZ];

int main()
{
    init();
    cin >> n >> a >> b >> c;
    for(int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        ll val = a*x + b*y + c;
        if(val > 0)
        {
            res += cnt2;
            cnt1++;
        } else if(val < 0)
        {
            res += cnt1;
            cnt2++;
        }
    }
    cout << res;
}
