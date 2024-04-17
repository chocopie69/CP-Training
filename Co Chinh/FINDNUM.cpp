#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "FINDNUM"

using namespace std;

const int SZ = 5e4+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int m,n,k,a[SZ],b[SZ];

struct cmp
{
    bool operator() (pii x, pii y)
    {
        return a[x.fi] + b[x.se] > a[y.fi] + b[y.se];
    }
};

priority_queue<pii,vector<pii>,cmp> pq;

int main()
{
    init();
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    sort(a+1,a+m+1);
    sort(b+1,b+n+1);
    for(int i = 1; i <= m; i++)
    {
        pq.push({i,1});
    }
    while(k--)
    {
        pii p = pq.top();
        pq.pop();
        cout << a[p.fi] + b[p.se] << '\n';
        if(p.se < n)
            pq.push({p.fi,p.se+1});
    }
}

/*
4 4 6
1 2 3 4
2 3 4 5
*/
