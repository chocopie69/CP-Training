#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "UPDATE"

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

int n,q;
ll a[SZ];

int main()
{
    init();
    cin >> n >> q;
    while(q--)
    {
        int lo,hi;
        ll x;
        cin >> lo >> hi >> x;
        a[lo] += x;
        a[hi+1] -= x;
    }
    for(int i = 1; i <= n; i++)
    {
        a[i] += a[i-1];
        cout << a[i] << " ";
    }
}
