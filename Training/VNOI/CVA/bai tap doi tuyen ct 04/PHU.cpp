#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "PHU"

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

int n,p,q, res = INF;
pii a[SZ];

int main()
{
    init();
    cin >> n >> p >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++)
    {
        if(a[i].fi > p) break;
        int cnt = 1, hi = a[i].se, mx = -INF;
        if(hi >= q)
        {
            cout << 1;
            return 0;
        }
        for(int j = i+1; j <= n; j++)
        {
            if(a[j].fi <= hi+1 && j != n)
            {
                mx = max(mx,a[j].se);
                //cout << a[j].fi << " " << a[j].se << '\n';
            } else
            {
                if(a[j].fi <= hi+1) mx = max(mx,a[j].se);
                if(mx == -INF) break;
                cnt++;
                hi = mx;
                //cout << hi << " lmao\n";
                if(hi >= q)
                {
                    res = min(res, cnt);
                    //cout << cnt << " ";
                    break;
                } else
                {
                    mx = -INF;
                    if(a[j].fi <= hi+1)
                    {
                        mx = max(mx,a[j].se);
                    } else break;
                }
            }
        }
    }
    cout << (res == INF ? 0 : res);
}

/*
6 1 5
-1 3
2 4
3 6
2 4
4 6
4 5
*/
