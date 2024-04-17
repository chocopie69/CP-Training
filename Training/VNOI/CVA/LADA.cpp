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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,k;
pll p[SZ];
ll sum[SZ];

bool touch(int i,int j,long long d) {
    long long x=abs(p[i].first-p[j].first);
    long long y=abs(p[i].second-p[j].second);
    return max(x,y)<=d*2;
}

bool check(int x)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            if(touch(i,j,sum[x])) return true;
        }
    }
    return false;
}

int main()
{
    init();
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    sum[0] = 1;
    for(int i = 1; i <= k; i++)
    {
        char c;
        cin >> c;
        sum[i] = sum[i-1] + int(c) - 48;
    }
    bool flag = false;
    int lo = 0, hi = k, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(check(mid))
        {
            hi = mid-1;
            flag = true;
        } else
        {
            lo = mid+1;
        }
    }
    cout << (flag ? lo : -1);
}
