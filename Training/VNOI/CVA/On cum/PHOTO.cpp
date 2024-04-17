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

int m,a,b,res;

int main()
{
    init();
    cin >> m >> a >> b;
    if(a > b) swap(a,b);
    m--;
    res = a;
    int L = 0, R = 2e9;
    while(L <= R)
    {
        int mid = (L+R)/2;
        if(mid/a + mid/b >= m)
        {
            R = mid-1;
        }
        else
        {
            L = mid+1;
        }
    }
    cout << L+res;
}

