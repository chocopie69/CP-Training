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

void build(int id, int lo, int hi)
{
    if(lo == hi)
    {
        seg[id] = a[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(2*id,lo,mid);
    build(2*id+1,mid+1,hi);
    seg[id] = seg[2*id] + seg[2*id+1];
}

void update(int id, int lo, int hi, int pos)
{
    if(lo > pos || hi < pos) return;
    if(lo == hi)
    {
        seg[id] = 1 - seg[id];
        return;
    }
    int mid = (lo + hi) / 2;
    update(2*id,lo,mid,pos);
    update(2*id+1,mid+1,hi,pos);
    seg[id] = seg[2*id] + seg[2*id+1];
}

ll query(int id, int lo, int hi, int val)
{
    if(lo == hi)
        return lo;
    int mid = (lo + hi) / 2;
    //if(lo == 1 && hi == 2) cout << seg[id] << " ";
    if(seg[2*id] >= val)
    {
        return query(2*id,lo,mid,val);
    } else if(seg[2*id+1] >= val - seg[2*id])
    {
        return query(2*id+1,mid+1,hi,val - seg[2*id]);
    }
    return -1;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1,1,n);
    //cout << seg[1] << '\n';
    while(m--)
    {
        int t,i;
        cin >> t >> i;
        if(t == 1)
        {
            update(1,1,n,i);
        } else
        {
            cout << query(1,1,n,i) << '\n';
        }
    }
}

/*
5 1
1 1 0 1 1
2 2
*/
