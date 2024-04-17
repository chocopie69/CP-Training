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

int n, p[SZ];
ll w[SZ], t[SZ], res = 0;
vector<int> adj[SZ];

struct Job
{
    ll w,t;
    Job(ll _w = 0, ll _t = 0) : w(_w), t(_t) {};

    bool operator < (const Job& other) const
    {
        return (double)w/t > (double) other.w / other.t;
    }
};

pair<Job,ll> get(Job x, Job y)
{
    return { {x.w + y.w, x.t + y.t}, x.t*y.w };
}

multiset<Job> jobs[SZ];

void dfs(int u, int prev)
{
    for(int v : adj[u])
    {
        if(v == prev) continue;
        dfs(v,u);
        if(jobs[u].size() < jobs[v].size()) swap(jobs[u], jobs[v]);
        for(Job x : jobs[v])
        {
            jobs[u].insert(x);
        }
    }
    Job cur = {w[u], t[u] };
    while(!jobs[u].empty() && !(cur < *jobs[u].begin()))
    {
        pair<Job,ll> top = get(cur, *jobs[u].begin());
        cur = top.first;
        jobs[u].erase(jobs[u].begin());
        res += top.se;
    }
    jobs[u].insert(cur);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
        p[i]++;
        adj[p[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    dfs(1,-1);
    ll d = 0;
    for(Job x : jobs[1])
    {
        res += x.w*d;
        d += x.t;
    }
    for(int i = 1; i <= n; i++)
    {
        res += t[i]*w[i];
    }
    cout << res;
}
