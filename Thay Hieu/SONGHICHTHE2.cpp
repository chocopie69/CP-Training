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

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int seg[4*SZ], n, a[SZ];

ll res = 0;
vector<int> nen;

void update(int id, int lo, int hi, int pos)
{
    seg[id]++;
    if(lo == hi) return;
    int mid = (lo + hi) / 2;
    if(pos <= mid)
    {
        update(2*id, lo, mid, pos);
    } else
    {
        update(2*id+1, mid+1, hi, pos);
    }
}

int query(int id, int lo, int hi, int u, int v)
{
    if(lo > v || hi < u) return 0;
    if(lo >= u && hi <= v) return seg[id];
    int mid = (lo + hi) / 2;
    return query(2*id,lo,mid,u,v) + query(2*id+1, mid+1, hi, u, v);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        nen.push_back(a[i]);
    }
    nen.erase(unique(all(nen)),nen.end());
    sort(all(nen));
    for(int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(all(nen),a[i]) - nen.begin() + 1;
        res += 1LL * query(1,1,n,a[i] + 1, n);
        update(1,1,n,a[i]);
    }
    cout << res;
}
