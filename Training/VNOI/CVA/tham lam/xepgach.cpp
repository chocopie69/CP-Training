#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "NAME"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, a[LIMIT], cur, res = 1;

int main()
{
    init();
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n,greater<int>());
    cur = a[0];
    for(int i = 1; i < n; i++)
    {
        if(cur <= 0)
            break;
        if(cur >0)
        {
            res++;
            cur--;
        }
        if(a[i]==0)
        {
            break;
        }
    }
    cout << res;
}

