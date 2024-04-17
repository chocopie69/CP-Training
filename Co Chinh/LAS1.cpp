#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "LAS1"

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

int n,d,a[SZ], res = 1;
map<int,int> mp;

int main()
{
    init();
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        int val;
        if(mp.find(a[i] - d) != mp.end())
        {
            val = mp[a[i]-d] + 1;
        } else
        {
            val = 1;
        }
        mp[a[i]] = val;
        //cout << val << '\n';
        res = max(res,val);
    }
    cout << res;
}
