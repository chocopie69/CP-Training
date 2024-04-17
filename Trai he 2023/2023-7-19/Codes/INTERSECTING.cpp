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
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<pii> v;
int n,pos[SZ], seg[SZ], res[SZ], a[SZ];

void update(int id, int lo, int hi, int pos, int val)
{
    if(lo > pos || hi < pos) return;
    if(lo == hi)
    {
        seg[id] += val;
        //cout << lo << " " << hi << '\n';
        return;
    }
    int mid = (lo + hi) / 2;
    update(2*id,lo,mid,pos,val);
    update(2*id+1,mid+1,hi,pos,val);
    seg[id] = seg[2*id] + seg[2*id+1];
}

int query(int id, int lo, int hi, int u, int v)
{
    if(lo > v || hi < u) return 0;
    if(lo >= u && hi <= v) return seg[id];
    int mid = (lo + hi) / 2;
    return query(2*id,lo,mid,u,v) + query(2*id+1,mid+1,hi,u,v);
}

int main()
{
    init();
    cin >> n;
    memset(pos,-1,sizeof(pos));
    for(int i = 1; i <= n*2; i++)
    {
        cin >> a[i];
        if(pos[a[i]] == -1)
        {
            pos[a[i]] = i;
        } else
        {
            v.push_back({pos[a[i]],i});
            update(1,1,2*n,i,1);
        }
    }
    sort(all(v));
    for(int i = n-1; i >= 0; i--)
    {
        update(1,1,2*n,v[i].se,-1);
        res[a[v[i].fi]] = query(1,1,2*n,v[i].fi,v[i].se);
        //update(1,1,2*n,v[i].fi,1);
        //cout << v[i].fi << " " << v[i].se << " " << a[v[i].fi] << " " << res[a[v[i].fi]] << '\n';
    }
    memset(seg,0,sizeof(seg));
    for(int i = n-1; i >= 0; i--)
    {
        res[a[v[i].fi]] += query(1,1,2*n,v[i].fi,v[i].se);
        update(1,1,2*n,v[i].fi,1);
        update(1,1,2*n,v[i].se,-1);
        //update(1,1,2*n,v[i].fi,1);
        //cout << v[i].fi << " " << v[i].se << " " << a[v[i].fi] << " " << res[a[v[i].fi]] << '\n';
    }
    for(int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
}
