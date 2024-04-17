#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,pos[SZ], x, y, res = 0;


int main()
{
    init();
    cin >> n;
    memset(pos, -1, sizeof(pos));
    for(int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        if(pos[x] != y)
        {
            if(pos[x] != -1)
                res++;
            pos[x] = y;
        }
    }
    cout << res;
}

