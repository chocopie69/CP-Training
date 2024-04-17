#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define pdd pair<double, double>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "BALLOONS"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
pdd a[SZ];

stack<pdd> st;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    for(int i = 1; i <= n; i++)
    {
        double x = a[i].fi, r = a[i].se;
        while(!st.empty())
        {
            double x1 = st.top().fi, r1 = st.top().se;
            r = min(r , (x1 - x) * (x1 - x) / (4 * r1) );
            if(r >= r1) st.pop();
            else break;
        }
        st.push({x,r});
        cout << fixed << setprecision(3) << r << '\n';
    }
}
