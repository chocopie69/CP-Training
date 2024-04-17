#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "TOWER"

using namespace std;

const int SZ = 1e6+3, LIM = 1e6;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin);
    freopen(TASKNAME".OUT","w",stdout);
}

struct Brick
{
    int a,b, id;
    ll h;
    Brick(int _a = 0, int _b = 0, ll _h = 0, int _id = 0) : a(_a), b(_b), h(_h), id(_id) {}

    bool operator < (const Brick& other) const
    {
        if(b != other.b) return b > other.b;
        return a < other.a;
    }
};

int n;
Brick bricks[SZ];
ll mx = 0, val;
int trace[SZ], d, pos, pos2;
stack<int> st;

struct Node
{
    ll val;
    int id;
    Node(ll _val = 0, int _id = -1) : val(_val), id(_id) {}

    Node operator + (const Node& other) const
    {
        if(val > other.val) return {val, id};
        return {other.val, other.id};
    }
};

Node seg[4*SZ];

void update(int id, int lo, int hi)
{
    if(lo == hi)
    {
        if(val > seg[id].val)
        {
            seg[id].val = val;
            seg[id].id = pos2;
        }
        return;
    }
    int mid = (lo + hi) / 2;
    if(pos <= mid)
    {
        update(2*id, lo, mid);
    } else
    {
        update(2*id+1, mid+1, hi);
    }
    seg[id] = seg[2*id] + seg[2*id+1];
}

Node query(int id, int lo, int hi)
{
    if(hi < pos) return {0,0};
    if(lo >= pos) return seg[id];
    int mid = (lo + hi) / 2;
    return query(2*id, lo, mid) + query(2*id+1, mid+1, hi);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int a,b;
        ll h;
        cin >> a >> b >> h;
        bricks[i] = {a,b,h,i};
    }
    sort(bricks + 1, bricks + n + 1);
    for(int i = 1; i <= n; i++)
    {
        pos = bricks[i].b;
        Node best = query(1,1,LIM);
        pos = bricks[i].a, pos2 = i, val = best.val + bricks[i].h;
        update(1, 1, LIM);
        trace[i] = best.id;
        if(best.val + bricks[i].h > mx)
        {
            mx = best.val + bricks[i].h;
            d = i;
        }
    }
    cout << mx << '\n';
    while(d != -1)
    {
        st.push(bricks[d].id);
        d = trace[d];
    }
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
