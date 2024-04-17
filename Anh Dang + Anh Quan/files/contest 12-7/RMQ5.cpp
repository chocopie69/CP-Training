#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
const int inf = 2e9;
const int N = 1e6+5;
const int mod = 1e9+7;
/*
struct node{
    int sum, len;
    ll inv;
    node(){
        sum = 0;
        len = 0;
        inv = 0;
    }
};

struct IT{
    int n;
    vector<int> st;
    IT(int _n){
        n = _n;
        st.resize(n*4+4, -inf);
    }
    void update(int id, int l, int r, int pos, int x){
        if(l == r){
            st[id] = max(st[id], x);
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid)update(id*2, l, mid, pos, x);
        else update(id*2+1, mid+1, r, pos, x);
        st[id] = max(st[id*2], st[id*2+1]);
    }
    void update(int pos, int x){
        update(1, 1, n, pos, x);
    }
    int get(int id, int l, int r, int u, int v){
        if(u <= l && r <= v)return st[id];
        if(u > r || l > v)return -inf;
        int mid = (l+r)/2;
        return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
    }
    int get(int l, int r){
        return get(1, 1, n, l, r);
    }
};
struct BIT {
    int n;
    vector<int> fe;
    BIT(int _n){
        n = _n;
        fe.resize(n+1, 0);
    }
    void add(int id, int x){
        for(; id <= n; id += id & -id)fe[id] += x;
    }
    int get(int id){
        int res = 0;
        for(; id; id -= id & -id)res += fe[id];
        return res;
    }
    int pos(int x){
        int id = 0, sum = 0;
        for(int i = 17; i >= 0; i --){
            id += (1<<i);
            if(id > n || sum+fe[id] > x)id -= (1<<i);
            else sum += fe[id];
        }
        return id+1;
    }
    int get(int l, int r){
        if(l > r)return 0;
        return get(r)-get(l-1);
    }

};
void dfs(int u, int p = -1){
    for(int v: adj[u]){
        if(v == p)continue;
        h[v] = h[u] + 1;
        P[v][0] = u;
        for(int i = 1; i < 20; i ++)P[v][i] = P[P[v][i-1]][i-1];
        dfs(v, u);
    }
}
int lca(int u, int v){
    if(h[u] < h[v])swap(u, v);
    int log = __lg(h[u]);
    for(int i = log; i >= 0; i --)if(h[u] >= h[v]+(1<<i))u = P[u][i];
    if(u == v)return u;
    for(int i = log; i >= 0; i --){
        if(P[u][i] && P[u][i] != P[v][i]){
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[v][0];
}
*/
vector<int> adj[N];
int n, m, k, a[N], b[N], pos[N], d[N], nxt[N][20], t, rmn[N][20];
ll ans, sum[N], s;

int get(int l, int r){
    int log = __lg(r-l+1);
    return min(rmn[l][log], rmn[r-(1<<log)+1][log]);
}
void sol(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++)cin >> a[i];
    for(int i = 1; i <= n; i ++){
        b[a[i]] = (i == n ? a[1] : a[i+1]);
    }
    for(int i = 1; i <= m; i ++)cin >> a[i];
    for(int i = m; i > 0; i --){
        nxt[i][0] = pos[b[a[i]]];
        pos[a[i]] = i;
    }
    for(int j = 1; j < 18; j ++){
        for(int i = 1; i <= m-(1<<j)+1; i ++){
            nxt[i][j] = nxt[nxt[i][j-1]][j-1];
        }
    }
    for(int i = 1; i <= m; i ++){
        int cur = i, lef = n-1;
        for(int j = 17; j >= 0; j --){
            if(lef >= (1<<j)){
		lef -= (1<<j);
                cur = nxt[cur][j];
            }
        }
        rmn[i][0] = (cur ? cur : m+1);
    }
    for(int j = 1; j < 18; j ++){
        for(int i = 1; i <= m-(1<<j)+1; i ++){
            rmn[i][j] = min(rmn[i][j-1], rmn[i+(1<<(j-1))][j-1]);
        }
    }
    while(k -- > 0){
        int l, r;
        cin >> l >> r;
        cout << (get(l, r) <= r);
    }
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    #define task "RMQ5"
        if(fopen(task".inp", "r")){
            freopen(task".inp", "r", stdin);
            freopen(task".out", "w", stdout);
        }
    int ntest = 1;
    //cin >> ntest;
    while(ntest -- > 0)sol();

}

