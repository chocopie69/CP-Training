#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setpre(n) fixed << setprecision(n)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define task ""

const int N = 6e5;

int n,dcp[3*N+5];
ll ans;

struct checkPoint
{
    int y;
    int x1,x2;
    int type; // 1 or -1
};
vector <checkPoint> p;
vector <int> cp;

struct SegmentTree
{
    int cnt[4*N+5],len[4*N+5];
    int i,j,d;
    void updateR(int id, int lo, int hi)
    {
        if (lo > j || hi < i){
            return;
        }
        if (i <= lo && hi <= j){
            cnt[id] += d;
            if (cnt[id]){
                len[id] = cp[hi+1] - cp[lo];
                //len[id] = cp[hi] + 1 - cp[lo];
            }
            else{
                if (lo == hi){ // leaf
                    len[id] = 0;
                }
                else{
                    len[id] = len[2*id] + len[2*id+1];
                }
            }
            return;
        }
        int mid = (lo + hi) / 2;
        updateR(2*id, lo, mid);
        updateR(2*id+1, mid+1, hi);
        if (cnt[id]){
            len[id] = cp[hi+1] - cp[lo];
        }
        else if(lo != hi) {
            len[id] = len[2*id] + len[2*id+1];
        } else len[id] = 0;
    }
    void update(int i, int j, int d)
    {
        SegmentTree::i = i;
        SegmentTree::j = j;
        SegmentTree::d = d;
        updateR(1, 0, N);
    }
} st;

signed main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(nullptr);
    // freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y,u,v; cin >> x >> u >> y >> v;
        p.pb({y, x, u, 1});
        p.pb({v, x, u, -1});
        cp.pb(x); cp.pb(u); cp.pb(u-1);
    }
    sort(all(cp));
    cp.erase(unique(all(cp)), cp.end());
    sort(all(cp));
    for (int i=0; i<sz(p); i++){
        p[i].x1 = lower_bound(all(cp), p[i].x1) - cp.begin();
        p[i].x2 = lower_bound(all(cp), p[i].x2) - cp.begin();
    }
    sort(all(p), [](checkPoint lo, checkPoint hi){
        // if (lo.y != hi.y) return (lo.y < hi.y);
        //return (lo.type > hi.type);
        return lo.y < hi.y;
    });
    //cout << sz(cp)<<'\n';
    ans = 0;
    for (int i=0; i<sz(p)-1; i++){
//        int y = p[i].y;
//        if (i > 0 && y != p[i-1].y){
//            prevy = p[i-1].y;
//            ans += (ll)st.len[1] * (y - prevy);
//        }
//        assert(1 <= p[i].x1 && p[i].x1 <= sz(cp));
//        st.update(p[i].x1, p[i].x2-1, p[i].type);
        //cout << p[i].y<<' '<<p[i].x1<<','<<p[i].x2<<'\n';
        st.update(p[i].x1, p[i].x2-1, p[i].type);
        //cout << "updated "<<st.len[1]<<'\n';
        ans += (ll)(p[i+1].y - p[i].y) * st.len[1];
        //cout << ans<<'\n';
    }
    cout << ans;
    return 0;
}
