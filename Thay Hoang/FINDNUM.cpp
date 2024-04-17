#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "FINDNUM"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,m,t;

int main()
{
    init();
    cin >> n >> m >> t;
    ll cnt = n/m;
    if(t <= cnt)
    {
        cout << m*t;
        return 0;
    }
    t -= cnt;
    ll md = n % m, cur;
    if(t <= md*(cnt+1))
    {
        cur = (t-1)/ (cnt+1) + 1;
        t = (t-1) % (cnt+1) + 1;
        cout << cur + m*(t-1);
        return 0;
    }
    t -= md*(cnt+1);
    cur = (t-1) / cnt + 1;
    t = (t-1) % cnt + 1;
    cout << (md+cur) + m*(t-1);

}

