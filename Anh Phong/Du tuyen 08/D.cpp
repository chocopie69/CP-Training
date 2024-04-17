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

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n, q, cnt = 0;
ll a[SZ];

struct PSegTree
{
    struct Node
    {
        ll val;
        Node *lf, *rt;

        Node(ll x) : val(x), lf(nullptr), rt(nullptr) {}
        Node(Node *_lf, Node *_rt)
        {
            lf = _lf;
            rt = _rt;
            if(lf != nullptr) val = lf->val;
            if(rt != nullptr) val += rt->val;
        }
        Node(Node *p) : val(p->val), lf(p->lf), rt(p->rt) {}
    };
    Node *roots[SZ];

    Node *build(int lo = 1, int hi = n)
    {
        if(lo == hi) return new Node(a[lo]);
        int mid = (lo + hi) / 2;
        return new Node(build(lo, mid), build(mid + 1, hi));
    }

    Node *update(Node *node, int pos, ll val, int lo = 1, int hi = n)
    {
        if(lo == hi) return new Node(val);
        int mid = (lo + hi) / 2;
        if(pos <= mid)
        {
            return new Node(update(node->lf, pos, val, lo, mid), node->rt);
        }
        return new Node(node->lf, update(node->rt, pos, val, mid+1, hi));
    }

    ll query(Node *node, int u, int v, int lo = 1, int hi = n)
    {
        if(lo > v || hi < u) return 0;
        if(lo >= u && hi <= v) return node->val;
        int mid = (lo + hi) / 2;
        return query(node->lf, u, v, lo, mid) + query(node->rt, u, v, mid+1, hi);
    }

} seg;

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    seg.roots[++cnt] = seg.build();
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int k, i;
            ll x;
            cin >> k >> i >> x;
            seg.roots[k] = seg.update(seg.roots[k], i, x);
        } else if(t == 2)
        {
            int k, u, v;
            cin >> k >> u >> v;
            cout << seg.query(seg.roots[k], u, v) << '\n';
        } else
        {
            int k;
            cin >> k;
            seg.roots[++cnt] = new PSegTree::Node(seg.roots[k]);
        }
    }
}

