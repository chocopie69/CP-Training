#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e2+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct Coordinate
{
    int x,y, id;
};

int n,dp[LIMIT],trace[LIMIT], res = 1, endIdx = 1;
Coordinate a[LIMIT];

bool cmp(Coordinate a, Coordinate b)
{
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

void recur(int i)
{
    if(i == -1) return;
    recur(trace[i]);
    cout << a[i].id << " ";
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x,y;
        cin >> x >> y;
        a[i].x = x;
        a[i].y = y;
        a[i].id = i;
    }
    sort(a+1,a+n+1,cmp);
    dp[1] = 1;
    trace[1] = -1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = 1;
        trace[i] = -1;
        for(int j = 1; j < i; j++)
        {
            if(a[j].y <= a[i].y)
            {
                if(dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                }
            }
        }
        if(dp[i] > res)
        {
            res = dp[i];
            endIdx = i;
        }
    }
    cout << res << '\n';
    recur(endIdx);
}
