#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "WINTER"

using namespace std;

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,a[SZ],p[SZ];
vector<int> adj[SZ];

ll res = 0, cur = 0, curRes;


void dfs(int u, int root)
{
    cur += a[u] - int(u == root);
    for(int v : adj[u])
    {
        dfs(v,root);
    }
}

namespace sub1
{
    void solve()
    {
        for(int bit = 0; bit < (1 << (n-1)); bit++)
        {
            curRes = 0;
            for(int i = 1; i <= n; i++)
            {
                adj[i].clear();
            }
            for(int i = 0; i < n-1; i++)
            {
                if(bit >> i & 1)
                {
                    adj[i+2].push_back(p[i+2]);
                } else
                {
                    adj[p[i+2]].push_back(i+2);
                }
            }
            for(int i = 1; i <= n; i++)
            {
                cur = 0;
                dfs(i,i);
                curRes += cur * a[i];
            }
            res = max(res,curRes);
        }
        cout << res;
    }
}

//struct Node
//{
//    ll u, dir, cnt,sum;
//    Node(ll _u = 0, ll _dir = 0, ll _cnt = 0, ll _sum = 0)
//    {
//        u = _u;
//        dir = _dir;
//        cnt = _cnt;
//        sum = _sum;
//    }
//};
//
//struct cmp
//{
//    bool operator () (Node x, Node y)
//    {
//        return x.sum < y.sum;
//    }
//};
//
//int start, deg[SZ];
//bool vis[SZ];
//ll d[SZ];
//
//priority_queue<Node, vector<Node>, cmp> pq;
//
//void bfs(int root)
//{
//    for(int i = 1; i <= n; i++)
//    {
//        d[i] = 0;
//    }
//    d[root] = a[root]-1;
//    vis[root] = true;
//    pq.push({root,1,a[root],a[root]-1});
//    while(!pq.empty())
//    {
//        Node cur = pq.top();
//        pq.pop();
//        ll u = cur.u, dir = pq.dir, cnt = pq.cnt, sum = pq.sum;
//        if(sum < d[u]) continue;
//        for(int v : adj[u])
//        {
//            if(dir == 1)
//            {
//                if(d[v] < d[u] + cnt)
//                {
//                    d[v] = d[u] + cnt;
//                }
//            }
//        }
//    }
//}
//
//namespace sub2
//{
//
//    void solve()
//    {
//        memset(deg,0,sizeof(deg));
//        memset(vis,false,sizeof(vis));
//        for(int i = 2; i <= n; i++)
//        {
//            adj[i].push_back(p[i]);
//            adj[p[i]].push_back(i);
//            deg[i]++;
//            deg[p[i]]++;
//        }
//        for(int i = 1; i <= n; i++)
//        {
//            if(deg[i] == 1)
//            {
//                start = i;
//                break;
//            }
//        }
//        bfs(start);
//    }
//}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 2; i <= n; i++)
    {
        cin >> p[i];
    }
    if(n <= 18)
        sub1::solve();
}
