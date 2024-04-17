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
}

int n,res = -INF, a[LIMIT], maxNum[LIMIT];

int main()
{
    init();
    cin >> n;
    maxNum[0] = -INF;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxNum[i] = max(maxNum[i-1], a[i]);
    }
    for(int i = n; i > 1; i--)
    {
        res = max(res,maxNum[i-1] - a[i]);
    }
    if(res > 0)
        cout << res;
    else
        cout << "Lo nang roi!";
}

