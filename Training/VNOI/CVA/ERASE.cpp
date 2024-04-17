#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "ERASE"

using namespace std;

const int SZ = 1e6+5, LIM = 20002;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, mx = 0;
pii a[SZ];
ll cnt = 1;
int u,v;

struct Node
{
    int mx;
    ll cnt;
    Node(int _mx = 0, ll _cnt = 1) : mx(_mx), cnt(_cnt) {}

    Node operator + (const Node& other) const
    {
        if(mx > other.mx) return {mx, cnt};
        else if(mx < other.mx) return other;
        return {mx, (mx == 0 ? 1 : cnt + other.cnt) };
    }
} seg[4*LIM];

//int u,v;

Node queryR(int id, int lo, int hi)
{
    if(lo > v || hi < u) return {0,1};
    if(lo >= u && hi <= v) return seg[id];
    int mid = (lo + hi) / 2;
    return queryR(2*id, lo, mid) + queryR(2*id+1, mid+1, hi);
}

Node query(int u, int v)
{
    ::u = u;
    ::v = v;
    return queryR(1, 1, LIM);
}

int pos;
Node val;

void updateR(int id, int lo, int hi)
{
    if(lo == hi)
    {
        seg[id] = seg[id] + val;
        return;
    }
    int mid = (lo + hi) / 2;
    if(pos <= mid)
    {
        updateR(2*id, lo, mid);
    } else
    {
        updateR(2*id+1, mid+1, hi);
    }
    seg[id] = seg[2*id] + seg[2*id+1];
}

void update(int pos, Node val)
{
    ::pos = pos;
    ::val = val;
    return updateR(1, 1, LIM);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
        a[i].fi += LIM/2;
        a[i].se += LIM/2;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        Node best = query(1, a[i].fi);
        best.mx++;
        if(best.mx == mx)
        {
            cnt += best.cnt;
        }
        if(best.mx > mx)
        {
            mx = best.mx;
            cnt = best.cnt;
        }
        update(a[i].se, best);
    }
    cout << n-mx << ' ' << cnt;
}
