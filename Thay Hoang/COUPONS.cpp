#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "COUPONS"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,k;
ll m;
pll a[SZ];
bool popped[SZ];

bool cmp(pll x, pll y)
{
    return x.se < y.se;
}

struct cmp1
{
    bool operator () (int x, int y)
    {
        return a[x].fi - a[x].se > a[y].fi - a[y].se;
    }
};

priority_queue<int,vector<int>,cmp1> pq1;

struct cmp2
{
    bool operator () (int x, int y)
    {
        return a[x].fi > a[y].fi;
    }
};

priority_queue<int,vector<int>,cmp2> pq2;

struct cmp3
{
    bool operator () (int x, int y)
    {
        return a[x].se > a[y].se;
    }
};

priority_queue<int,vector<int>,cmp3> pq3;

int res = 0;

int main()
{
    init();
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1,cmp);
    int pos = k+1;
    for(int i = 1; i <= k; i++)
    {
        if(m - a[i].se < 0)
        {
            cout << i-1;
            return 0;
        }
        m -= a[i].se;
        pq1.push(i);
    }
    res = k;
    for(int i = k+1; i <= n; i++)
    {
        pq2.push(i);
        pq3.push(i);
    }
    while(!pq2.empty() && !pq3.empty())
    {
        ll sol1, sol2;
        if(!pq1.empty())
        {
            int x = pq1.top();
            while(!pq3.empty() && popped[pq3.top()]) pq3.pop();
            if(pq3.empty())
            {
                sol1 = INFLL;
            } else
            {
                int y = pq3.top();
                sol1 = a[x].fi - a[x].se + a[y].se;
            }
        }
        while(!pq2.empty() && popped[pq2.top()]) pq2.pop();
        if(pq2.empty())
        {
            sol2 = INFLL;
        } else
        {
            int y = pq2.top();
            sol2 = a[y].fi;
        }
        if(m - min(sol1,sol2) < 0) break;
        if(sol1 < sol2 && m - sol1 >= 0)
        {
            m -= sol1;
            popped[pq3.top()] = true;
            pq1.pop();
            pq1.push(pq3.top());
            pq3.pop();
            res++;
        }
        if(sol2 <= sol1 && m - sol2 >= 0)
        {
            m -= sol2;
            popped[pq2.top()] = true;
            pq2.pop();
            res++;
        }
    }
    cout << res;
}
