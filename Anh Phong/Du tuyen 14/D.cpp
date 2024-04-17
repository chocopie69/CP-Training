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
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 5e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n, a[SZ];
string s;

struct SegTree
{
    struct Node
    {
        int sum, pref, suff, res;
        Node operator + (const Node& other) const
        {
            Node cur;
            cur.sum = sum + other.sum;
            cur.pref = max(pref, sum + other.pref);
            cur.suff = max(other.suff, other.sum + suff);
            cur.res = max({ res + other.sum, other.res + sum, pref + other.suff });
            return cur;
        }
    } nodes[4*SZ];

    void build(int id = 1, int lo = 1, int hi = n)
    {
        if(lo == hi)
        {
            if(s[lo] == 'T') nodes[id] = {1, 1, 1, 1};
            else nodes[id] = {-1, 0, 0, 0};
            return;
        }
        int mid = (lo + hi) / 2;
        build(2*id, lo, mid);
        build(2*id+1, mid+1, hi);
        nodes[id] = nodes[2*id] + nodes[2*id+1];
    }

    Node query(int u, int v, int id = 1, int lo = 1, int hi = n)
    {
        if(lo > v || hi < u) return {0,0,0,0};
        if(lo >= u && hi <= v) return nodes[id];
        int mid = (lo + hi) / 2;
        return query(u, v, 2*id, lo, mid) + query(u,v, 2*id+1, mid+1, hi);
    }
} st;

int main()
{
    init();
    cin >> n >> s;
    s = " " + s;
    st.build();
    int q;
    cin >> q;
    while(q--)
    {
        int lo,hi;
        cin >> lo >> hi;
        cout << st.query(lo, hi).res << '\n';
    }
}

