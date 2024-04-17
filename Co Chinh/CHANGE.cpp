#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CHANGE"

using namespace std;

const int SZ = 1e7+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

ll k,x,y, pow10[SZ];

int getLength(ll num)
{
    int cnt = 0;
    while(num > 0)
    {
        num /= 10;
        cnt++;
    }
    return cnt;
}

ll spin(ll num)
{
    int len = getLength(num);
    return (num % pow10[len-1]) * 10LL + (num / pow10[len-1]);
}

namespace sub1
{
    bool vis[SZ];
    int d[SZ], trace[SZ];
    queue<int> qu;

    void recur(int num)
    {
        if(num == -1) return;
        recur(trace[num]);
        cout << num << '\n';
    }

    void solve()
    {
        qu.push(x);
        d[x] = 0;
        trace[x] = -1;
        vis[x] = true;
        while(!qu.empty())
        {
            int cur = qu.front();
            qu.pop();
            if(!vis[cur+1] && cur < pow10[k])
            {
                vis[cur+1] = true;
                d[cur+1] = d[cur] + 1;
                trace[cur+1] = cur;
                qu.push(cur+1);
            }
            ll nx = spin(cur);
            if(!vis[nx])
            {
                vis[nx] = true;
                d[nx] = d[cur] + 1;
                trace[nx] = cur;
                qu.push(nx);
            }
        }
        cout << d[y] << '\n';
        //cout << trace[232] << " " << trace[231] << " " << trace[123];
        recur(y);
    }
}

namespace sub2
{
    bool flag = false;
    vector<ll> vec;

    void recur(ll cur, int cnt)
    {
        if(cur == y && !flag)
        {
            cout << vec.size()-1 << '\n';
            for(ll num : vec) cout << num << '\n';
            flag = true;
            return;
        }
        if(flag || cnt >= 21) return;
        if(cur < pow10[k])
        {
            vec.push_back(cur+1);
            recur(cur+1,cnt+1);
            vec.pop_back();
        }
        vec.push_back(spin(cur));
        recur(spin(cur),cnt+1);
        vec.pop_back();
    }

    void solve()
    {
        vec.push_back(x);
        recur(x, 0);
    }
}

int main()
{
    init();
    cin >> k >> x >> y;
    pow10[0] = 1LL;
    for(int i = 1; i <= k; i++)
    {
         pow10[i] = pow10[i-1] * 10LL;
    }
    //cout << getLength(123) << " " << spin(123) << '\n';
    if(k <= 6)
        sub1::solve();
    else
        sub2::solve();
}
