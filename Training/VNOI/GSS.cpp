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

ll n,m,a[SZ], u,v;

struct Node
{
    ll sum, prefix, suffix, res;
    Node(ll _sum = 0, ll _prefix = 0, ll _suffix = 0, ll _res = 0)
    {
        sum = _sum;
        prefix = _prefix;
        suffix = _suffix;
        res = _res;
    }

    Node operator + (const Node& other) const
    {
        return {sum + other.sum, max(prefix,sum + other.prefix), max(other.suffix, other.sum + suffix), max({res,other.res,suffix + other.prefix}) };
    }
};

Node seg[SZ];

void buildTree(int id, int lo, int hi)
{
    if(lo == hi)
    {
        seg[id] = { a[lo], a[lo], a[lo], a[lo] };
        return;
    }
    int mid = (lo + hi) / 2;
    buildTree(2*id, lo,mid);
    buildTree(2*id+1,mid+1,hi);
    seg[id] = seg[2*id] + seg[2*id+1];
}

Node query(int id, int lo, int hi)
{
    if(lo > v || hi < u) return {0,-INFLL,-INFLL,-INFLL};
    if(lo >= u && hi <= v) return seg[id];
    int mid = (lo + hi) / 2;
    return query(2*id,lo,mid) + query(2*id+1,mid+1,hi);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    buildTree(1,1,n);
    cin >> m;
    while(m--)
    {
        cin >> u >> v;
        cout << query(1,1,n).res << '\n';
    }
}
