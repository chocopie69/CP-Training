#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define pbi pair<TBigNum, int>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "ONEZERO"

using namespace std;

const int SZ = 2e6+5;
const ll INF = INT_MAX / 2, MOD = 1e17, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll t,x;
bool vis[SZ], flag;
pll trace[SZ];

queue<int> qu;

void recur(int x)
{
    if(x == -1) return;
    recur(trace[x].se);
    cout << trace[x].fi;
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> x;
        for(int i = 0; i < x; i++)
        {
            vis[i] = false;
            trace[i] = {0,0};
        }
        flag = false;
        while(!qu.empty()) qu.pop();
        qu.push(1 % x);
        trace[1 % x] = {1,-1};
        vis[1 % x] = true;
        while(!qu.empty())
        {
            ll m = qu.front();
            qu.pop();
            //if(vis[m]) continue;
            //vis[m] = true;
            if(m == 0)
            {
                recur(m);
                cout << '\n';
                flag = true;
                break;
            }
            ll nextm = (m * (10%x) ) % x;
            if(!vis[nextm])
            {
                qu.push(nextm);
                vis[nextm] = true;
                trace[nextm] = {0,m};
            }
            nextm = (m * 10 + 1) % x;
            if(!vis[nextm])
            {
                qu.push(nextm);
                vis[nextm] = true;
                trace[nextm] = {1,m};
            }
        }
        if(!flag) cout << "BRAK" << '\n';
    }
}
