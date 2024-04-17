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

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

ll m,w,n, a[SZ], cnt[SZ];

struct SegmentTree
{
    ll nodes[4*SZ];

    void buildR(int id, int lo, int hi)
    {
        if(lo == hi)
        {
            nodes[id] = w;
            return;
        }
        int mid = (lo + hi) / 2;
        buildR(2*id, lo, mid);
        buildR(2*id+1, mid+1, hi);
        nodes[id] = max(nodes[2*id], nodes[2*id+1]);
    }

    void build()
    {
        buildR(1, 1, n);
    }

    int pos;
    ll val;

    void updateR(int id, int lo, int hi)
    {
        if(lo > pos || hi < pos) return;
        if(lo == hi)
        {
            nodes[id] = val;
            return;
        }
        int mid = (lo + hi) / 2;
        updateR(2*id, lo, mid);
        updateR(2*id+1, mid+1, hi);
        nodes[id] = max(nodes[2*id], nodes[2*id+1]);
    }

    void update(int pos, ll val)
    {
        SegmentTree::pos = pos;
        SegmentTree::val = val;
        updateR(1, 1, n);
    }

    ll queryR(int id, int lo, int hi)
    {
        if(lo > pos) return 0;
        if(hi <= pos) return nodes[id];
        int mid = (lo + hi) / 2;
        return max(queryR(2*id, lo, mid), queryR(2*id+1,mid+1, hi));
    }

    ll query(int pos)
    {
        SegmentTree::pos = pos;
        return queryR(1, 1, n);
    }
} st;

int main()
{
    init();
    cin >> m >> w >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[i] = w;
    }
    st.build();
    for(int i = 1; i <= n; i++)
    {
        int lo = 1, hi = min(m,n), mid;
        bool flag = false;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(st.query(mid) >= a[i])
            {
                hi = mid-1;
                flag = true;
            } else
            {
                lo = mid+1;
            }
        }
        if(!flag)
        {
            cout << -1 << '\n';
            continue;
        }
        cout << lo << '\n';
        cnt[lo] -= a[i];
        st.update(lo, cnt[lo]);
    }
}
