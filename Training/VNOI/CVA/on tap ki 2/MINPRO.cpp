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

ll a,b,x,y,n,t, res;

ll solve(ll curA, ll curB, ll curN)
{
    //cout << curA << ' ' << curB << '\n';
    if(curA-x <= curN)
    {
        curN -= (curA-x);
        curA = x;
        curB = max(curB-curN,y);
    }
    else
    {
        curA -= curN;
    }
    //cout << curA << " " << curB << '\n';
    return curA * curB;
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> x >> y >> n;
        if(a-x + b-y <= n)
        {
            cout << x*y << '\n';
            continue;
        }
        res = solve(a,b,n);
        swap(a,b);
        swap(x,y);
        res = min(res,solve(a,b,n));
        cout << res << '\n';
    }
}

