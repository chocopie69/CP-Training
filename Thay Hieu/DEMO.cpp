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
        else if(priority != other.priority) return priority < other.priority;
        return false;
    }
};

vector<Update> updates;

Coord a[SZ];

vector<ll> nenx, neny;
ll oldx[SZ], oldy[SZ], xr[SZ], xl[SZ], res = 0, maxq[SZ];
bool vis[SZ], existu2[SZ];

struct Node
{
    ll sum, cnt;
    Node(ll _sum = 0, ll _cnt = 0)
    {
        sum = _sum;
        cnt = _cnt;
    }

    Node operator + (const Node& other) const
    {
        return {sum + other.sum, cnt + other.cnt };
    }
};

Node seg[4*SZ];

void updateSeg(int id, int lo, int hi, int pos, ll val)
{
    if(lo == hi)
    {
        if(val == 1)
        {
            if(seg[id].sum == 0) seg[id].cnt = 1;
            seg[id].sum += val;
        } else
        {
            seg[id].sum += val;
            if(seg[id].sum == 0) seg[id].cnt = 0;
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
    if(lo > v || hi < u || u > v) return {0,0};
    if(lo >= u && hi <= v) return seg[id];
    int mid = (lo + hi) / 2;
    return query(2*id, lo, mid, u, v) + query(2*id+1, mid+1, hi, u, v);
}

ll getX(ll x)
{
    return lower_bound(all(nenx),x) - nenx.begin() + 1;
}

ll getY(ll y)
{
    return lower_bound(all(neny),y) - neny.begin() + 1;
}

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

    /// Can them nhung toa do nay de khi nen chi so khong bi sai
    neny.push_back(0);
    neny.push_back(1);
    neny.push_back(n);
    neny.push_back(n+1);

    nenx.push_back(1);
    nenx.push_back(m);


    sort(all(neny));
    for(int i = 1; i <= k; i++)
    {
        ll pos = getY(a[i].y);
        oldy[pos] = a[i].y;
        a[i].y = pos;
    }
    sort(all(nenx));;
    for(int i = 0; i <= k+4; i++)
    {
        xr[i] = getY(n+1);
        xl[i] = getY(0);
    }
    for(int i = 1; i <= k; i++)
    {
        ll pos = getX(a[i].x);
        oldx[pos] = a[i].x;
        a[i].x = pos;
        if(a[i].dir == 'N') xr[pos] = min(xr[pos], a[i].y);
        if(a[i].dir == 'S') xl[pos] = max(xl[pos], a[i].y);
    }
    for(int i = 1; i <= k; i++)
    {
        if(a[i].dir == 'E')
        {
            updates.push_back({a[i].x, a[i].y, 1, 1 });
            updates.push_back({getX(m), a[i].y, 3, -1 });
        }
        else if(a[i].dir == 'W')
        {
            updates.push_back({ getX(1), a[i].y, 1, 1 });
            updates.push_back({ a[i].x , a[i].y, 3, -1 });
        } else
        {
            if(!vis[ a[i].x ])
            {
                vis[a[i].x] = true;
                updates.push_back({ a[i].x, 0, 2, 0 }); /// nen cac duong doc voi cung toa do x thanh 1
            }
        }
    }
    sort(all(updates));
    ll prevx = 0;
    oldy[getY(0)] = 0;
    oldy[getY(n+1)] = n+1;
    oldx[getX(m)] = m;
    oldx[getX(1)] = 1;
    for(Update u : updates)
    {
        ll x = u.x, y = u.y, priority = u.priority, val = u.val;
        if(x != prevx) res += (oldx[x] - oldx[prevx] - 1) * query(1,1,k+4,1,k+4).cnt; /// tinh so luong o duoc to nam giua cot x va prevx, khong tinh cot x va prevx vi se duoc tinh sau
        prevx = x;
        if(u.priority != 2)
        {
            maxq[x] = max(maxq[x],query(1,1,k+4,1,k+4).cnt);
            updateSeg(1,1,k+4,y,val);
            maxq[x] = max(maxq[x],query(1,1,k+4,1,k+4).cnt); /// cap nhat so luong o tren cot x
        } else
        {
            existu2[x] = true;
            int lo = xl[x], hi = xr[x];
            ll cur = 0;
            if(lo >= hi-1)
            {
                res += n;
            } else
            {
                res += query(1,1,k+4,lo + 1, hi - 1).cnt + (n - oldy[hi] + 1) + oldy[lo];
            }
        }
    }

    /// Tinh rieng so luong o tren cac cot x ma x co trong toa do de bai
    for(int i = 0; i <= k+4; i++)
    {
        if(maxq[i] != 0 && !existu2[i])
        {
            res += maxq[i];
        }
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
