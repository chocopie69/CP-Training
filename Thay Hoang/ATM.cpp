#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "ATM"

using namespace std;

const int SZ = 2e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n;
ll m, a[SZ], res = 0;
bool vis[SZ];
vector<ll> vec[3];

void gen(int pos,int l, int r, int id, ll sum, int choosed)
{
    if(!vis[choosed]) vec[id].push_back(sum);
    vis[choosed] = true;
    if(pos > r) return;
    gen(pos+1, l, r, id, sum, choosed);
    gen(pos+1, l, r, id, sum + a[pos], choosed + (1 << (pos-l)));
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    gen(1,1, n/2,1, 0, 0);
    memset(vis,false,sizeof(vis));
    gen(n/2+1,n/2+1, n,2, 0, 0);
    sort(all(vec[1]));
    sort(all(vec[2]));
    for(ll x : vec[1])
    {
        int pos = lower_bound(all(vec[2]), m-x) - vec[2].begin();
        if(vec[2][pos] != m-x) continue;
        int pos2 = upper_bound(all(vec[2]), m-x) - vec[2].begin();
        res += pos2-pos;
        //cout << x << " ";
    }
//    cout << '\n';
//    for(ll x : vec[2])
//    {
//        cout << x << " ";
//    }
    cout << res;
}
