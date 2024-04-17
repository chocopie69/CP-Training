#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "WALL"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m,a[SZ],b[SZ], cnt = 0;

bool check(int x)
{
    int j = 1;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] >= x) continue;
        while(j <= m && a[i] + b[j] < x) j++;
        if(j > m) return false;
        j++;
    }
    return true;
}

vector<pii> res;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    int lo = 1, hi = int(1e9), mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(check(mid))
        {
            lo = mid+1;
        } else
        {
            hi = mid-1;
        }
    }
    cout << hi << " ";
    int j = 1;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] >= hi) continue;
        while(j <= m && a[i] + b[j] < hi) j++;
        res.push_back({i,j});
        j++;
        cnt++;
    }
    cout << cnt << '\n';
    for(pii p : res)
    {
        cout << p.fi << " " << p.se << '\n';
    }
}

/*
6
2 5 4 4 7 5
7
2 3 1 3 2 4 6
*/
