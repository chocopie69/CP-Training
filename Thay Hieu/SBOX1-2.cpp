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

int n,q;

struct FenwickTree
{
    ll sum[SZ];

    void update(int pos, ll val)
    {
        int i = pos;
        while(i <= n)
        {
            sum[i] += val;
            i += (i & -i);
        }
    }

    ll getSum(int pos)
    {
        ll cur = 0;
        int i = pos;
        while(i >= 1)
        {
            cur += sum[i];
            i -= (i & -i);
        }
        return cur;
    }
} ft;

int main()
{
    init();
    cin >> n >> q;
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int pos;
            ll val;
            cin >> pos >> val;
            ft.update(pos,val);
        } else
        {
            int u,v;
            cin >> u >> v;
            cout << ft.getSum(v) - ft.getSum(u-1) << '\n';
        }
    }
}
