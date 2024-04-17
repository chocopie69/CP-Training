#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SUBSETS"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string toString(int x)
{
    ostringstream oss;
    oss << x;
    return oss.str();
}

int n, k;
bool vis[SZ];

void recur(int i, string s, int prev)
{
    if(i == 0)
    {
        cout << s << '\n';
        return;
    }
    for(int j = 1; j <= n; j++)
    {
        if(!vis[j])
        {
            vis[j] = true;
            recur(i-1, s + toString(j) + " ", j);
            vis[j] = false;
        }
    }
}

int main()
{
    init();
    cin >> n >> k;
    memset(vis,false,sizeof(vis));
    recur(k, "", 0);
}


