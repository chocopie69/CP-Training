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

ll n,m,k;

int type(char dir)
{
    if(dir == 'W' || dir == 'E') return 1;
    return 2;
}

struct Coord
{
    ll x,y;
    char dir;
    Coord(ll _x = 0, ll _y = 0, char _dir = 0)
    {
        x = _x;
        y = _y;
        dir = _dir;
    }

    bool operator < (const Coord& other) const
    {
        if(x != other.x) return x < other.x;
        return type(dir) <= type(other.dir);
    }
};

struct Update
{
    ll x,y,priority,val;
    Update(ll _x = 0, ll _y = 0, ll _priority = 0, ll _val = 0)
    {
        x = _x;
        y = _y;
        priority = _priority;
        val = _val;
    }
    bool operator < (const Update& other) const
    {
        if(x != other.x) return x < other.x;
        return priority <= other.priority;
    }
};

vector<Update> updates;

Coord a[SZ];

vector<ll> nenx, neny;
ll oldx[SZ], oldy[SZ], xr[SZ], xl[SZ], cntu1[SZ], res = 0;
bool vis[SZ];

struct Node
{
    bool zero;
    ll cnt;
    Node(bool _zero = true, ll _cnt = 0)
    {
        zero = _zero;
        cnt = _cnt;
    }

    Node operator + (const Node& other) const
    {
        return {zero && other.zero, cnt + other.cnt };
    }
};

Node seg[4*SZ];

void updateSeg(int id, int lo, int hi, int pos, ll val)
{
    if(lo == hi)
    {
        if(val == 1)
        {
            if(seg[id].zero)
            {
                seg[id].cnt++;
                seg[id].zero = false;
            }
        } else
        {
            seg[id].cnt--;
            if(seg[id].cnt <= 0) seg[id].zero = true;
        }
        return;
    }
    int mid = (lo + hi) / 2;
    if(pos <= mid) updateSeg(2*id, lo, mid, pos, val);
    else updateSeg(2*id+1, mid+1, hi, pos, val);
    seg[id] = seg[2*id] + seg[2*id+1];
}

Node query(int id, int lo, int hi, int u, int v)
{
    if(lo > v || hi < u || u > v) return {true,0};
    if(lo >= u && hi <= v) return seg[id];
    int mid = (lo + hi) / 2;
    return query(2*id, lo, mid, u, v) + query(2*id+1, mid+1, hi, u, v);
}

ll maxq[SZ];
bool existu2[SZ];

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++)
    {
        ll x,y;
        char dir;
        cin >> x >> y >> dir;
        swap(x,y);
        a[i] = {x,y,dir};
        nenx.push_back(x);
        neny.push_back(y);
    }
    neny.erase(unique(all(neny)),neny.end());
    sort(all(neny));
    for(int i = 1; i <= k; i++)
    {
//        ll pos = lower_bound(all(neny),a[i].y) - neny.begin() + 1;
//        oldy[pos] = a[i].y;
//        a[i].y = pos;
        oldy[a[i].y] = a[i].y;
    }
    nenx.erase(unique(all(nenx)),nenx.end());
    sort(all(nenx));
    for(int i = 0; i <= 100000; i++)
    {
        xr[i] = n+1;
        xl[i] = 0;
    }
    for(int i = 1; i <= k; i++)
    {
//        ll pos = lower_bound(all(nenx),a[i].x) - nenx.begin() + 1;
//        oldx[pos] = a[i].x;
//        a[i].x = pos;
        oldx[a[i].y] = a[i].y;
        ll pos = a[i].x;
        if(a[i].dir == 'N') xr[pos] = min(xr[pos], a[i].y);
        if(a[i].dir == 'S') xl[pos] = max(xl[pos], a[i].y);
    }
    sort(a + 1, a + k);
    for(int i = 1; i <= k; i++)
    {
        if(a[i].dir == 'E')
        {
            updates.push_back({a[i].x, a[i].y, 1, 1 });
            updates.push_back({m, a[i].y, 3, -1 });
        }
        else if(a[i].dir == 'W')
        {
            updates.push_back({ 1, a[i].y, 1, 1 });
            updates.push_back({ a[i].x , a[i].y, 3, -1 });
        } else
        {
            if(!vis[ a[i].x ])
            {
                vis[a[i].x] = true;
                updates.push_back({ a[i].x, 0, 2, 0 });
            }
        }
    }
    sort(all(updates));
    ll prevx = 0;
    oldy[n+1] = n+1;
    //for(Update u : updates)
    for(Update u : updates)
    {
        //cout << u.x << " " << u.y << " " << u.priority << " " << u.val << '\n';
        ll x = u.x, y = u.y, priority = u.priority, val = u.val;
        res += max((x - prevx - 1),0LL) * query(1,1,k,1,k).cnt;
        //cout << x << " " << prevx << " " << max((x - prevx - 1),0LL) << " " << query(1,1,k,1,k).cnt << '\n';
        if(u.priority != 2)
        {
            if(u.priority == 3)
            {
                maxq[x] = query(1,1,k,1,k).cnt;
            }
            updateSeg(1,1,k,y,val);
            if(u.priority == 1)
            {
                maxq[x] = query(1,1,k,1,k).cnt;
            }
        } else
        {
            existu2[x] = true;
            int lo = xl[x], hi = xr[x];
            ll cur = 0;
            if(lo >= hi-1)
            {
                res += n;
                //cout << x << " " << y << " +" << n << '\n';
            } else
            {
                res += query(1,1,k,lo + 1, hi - 1).cnt + (n - hi + 1) + lo;
                //res -= query(1,1,k,1,k).cnt;
                //cout << lo << " " << hi << '\n';
                //cout << x << " " << y << " " << priority << " " << val << " " << lo << " " << hi << " " << query(1,1,k,lo + 1, hi - 1).cnt << " " << (n - hi + 1) << " " << lo << " " << cntu1[x] << '\n';
            }
            //res -= cntu1[x];
            //cout << x << " " << y << " -" << cntu1[x] << '\n';
            //cur -= cntu1[x];
            //cout << x << " " << y << " " << priority << " " << val << " " << lo << " " << hi << " " << query(1,1,k,lo + 1, hi - 1).cnt << " " << (n - hi + 1) << " " << lo << " " << cntu1[x] << '\n';
        }
        //if(prevx != x) res += query(1,1,k,1,k).cnt;
        prevx = x;
    }
    for(int i = 1; i <= 100000; i++)
    {
        if(maxq[i] != 0 && !existu2[i]) res += maxq[i];
        //cout << i << " " << maxq[i] << '\n';
    }
    cout << res;
}

/*
    5 8
    5
    4 4 S
    2 6 W
    3 6 N
    4 6 S
    5 4 E
*/
