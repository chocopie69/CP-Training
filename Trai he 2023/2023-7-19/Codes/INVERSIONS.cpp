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

ll n,m,a[SZ],seg[4*SZ];

void update(int id, int lo, int hi, int pos)
{
    if(lo > pos || hi < pos) return;
    if(lo == hi)
    {
        seg[id]++;
        return;
    }
    int mid = (lo + hi) / 2;
    update(2*id,lo,mid,pos);
    update(2*id+1,mid+1,hi,pos);
    seg[id] = seg[2*id] + seg[2*id+1];
}

ll query(int id, int lo, int hi, int u, int v)
{
    if(lo > v || hi < u)
        return 0;
    if(lo >= u && hi <= v)
        return seg[id];
    int mid = (lo + hi) / 2;
    return query(2*id,lo,mid,u,v) + query(2*id+1,mid+1,hi,u,v);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cout << query(1,1,n,a[i]+1,n) << ' ';
        update(1,1,n,a[i]);
    }
}
