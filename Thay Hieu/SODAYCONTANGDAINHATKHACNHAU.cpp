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

struct Node
{
    ll mx, cnt;

    Node(ll _mx = 0, ll _cnt = 1)
    {
        mx = _mx;
        cnt = _cnt;
    }

    Node operator + (const Node& other) const
    {
        if(mx == other.mx) return {mx, (mx == 0 ? 1LL : (cnt + other.cnt) % MOD ) };
        if(mx > other.mx) return {mx, cnt};
        return other;
    }
};

int n, last[SZ];
Node seg[4*SZ];
ll mx = 0, res = 0, a[SZ];
vector<ll> nen;
stack<int> st[SZ];

pll b[SZ];

Node query(int id, int lo, int hi, int u, int v)
{
    if(u > v || lo > v || hi < u) return {0,1};
    if(lo >= u && hi <= v) return seg[id];
    int mid = (lo + hi) / 2;
    return query(2*id, lo, mid, u, v) + query(2*id+1, mid+1, hi, u, v);
}

void update(int id, int lo, int hi, int pos, Node val)
{
    if(lo == hi)
    {
        seg[id] = seg[id] + val;
        return;
    }
    int mid = (lo + hi) / 2;
    if(pos <= mid) update(2*id,lo,mid,pos,val);
    else update(2*id+1,mid+1,hi,pos,val);
    seg[id] = seg[2*id] + seg[2*id+1];
}

stack<pair<int, pll>> updates;

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
        if(!st[a[i]].empty()) last[i] = st[a[i]].top();
        st[a[i]].push(i);
        b[i] = {a[i],i };
//        Node best = query(1,1,n,1, a[i] - 1);
//        if(best.mx + 1 == mx)
//        {
//            res = (res + best.cnt) % MOD;
//        }
//        if(best.mx + 1 > mx)
//        {
//            mx = best.mx + 1;
//            res = best.cnt;
//        }
//        update(1,1,n,a[i], {best.mx + 1, best.cnt });
    }
    sort(b + 1, b + n + 1);
    ll prev = -1;
    for(int i = 1; i <= n; i++)
    {
        ll x = b[i].fi, pos = b[i].se;
        if(x != prev)
        {
            while(!updates.empty())
            {
                update(1,1,n, updates.top().fi, { updates.top().se.fi, updates.top().se.se });
                updates.pop();
            }
        }
        //cout << b[i].fi << " " << prev << '\n';
        prev = x;
        Node best = query(1,1,n, last[pos] + 1 , pos - 1);
        if(best.mx == 0 && last[pos] != 0) best.cnt = 0;
        if(best.mx + 1 == mx)
        {
            res = (res + best.cnt) % MOD;
        }
        if(best.mx + 1 > mx)
        {
            mx = best.mx + 1;
            res = best.cnt;
        }
        //cout << x << " " << pos << " " << best.mx << " " << best.cnt << '\n';
        //cout << pos << " " << last[pos] << '\n';
        //update(1,1,n, pos, {best.mx + 1, best.cnt });
        updates.push( {pos, { best.mx + 1, best.cnt } });
    }
    cout << res;
    //cout << " " << mx;
}