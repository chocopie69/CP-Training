#include<bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
const int inf = 2e9;
const int N = 1e6+5;
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
vector<int> add[N], del[N];
int n, m, k, a[N], b[N], id[N], pos[N], rmq[N][20];
ll ans, sum;
bool cmp(const int& x, const int& y){
    return (b[x] < b[y]) || (b[x] == b[y] && x < y);
}
int get(int l, int r){
    int lg = __lg(r-l+1);
    return min(rmq[l][lg], rmq[r-(1<<lg)+1][lg]);
}
void sol(){

    cin >> n;
    for(int i =1 ; i <= n; i ++){
        cin >> rmq[i][0];
        ans += rmq[i][0];
    }
    for(int j = 1; j < 20; j ++){
        for(int i = 1; i <= n-(1<<j)+1; i ++){
            rmq[i][j] = min(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i = 2; i <= n; i ++){
        if(n % i == 0){
            sum = 0;
            for(int j = i; j <= n; j += i)sum += get(j-i+1, j);
            ans = max(ans, sum*i*i);
        }
    }
    cout << ans;

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    #define task "RMQ4"
        if(fopen(task".inp", "r")){
            freopen(task".inp", "r", stdin);
            freopen(task".out", "w", stdout);
        }
    int ntest = 1;
    //cin >> ntest;
    while(ntest -- > 0)sol();

}
