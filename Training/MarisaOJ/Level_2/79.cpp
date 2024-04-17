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
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,q,a[SZ];
vector<int> pos[SZ];

int cnt(int val, int hi)
{
    return upb(all(pos[val]), hi) - pos[val].begin() - 1;
}

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pos[a[i]].pb(i);
    }
    while(q--)
    {
        int lo,hi,x;
        cin >> lo >> hi >> x;
        cout << cnt(x, hi) - cnt(x, lo-1) << '\n';
    }
}

