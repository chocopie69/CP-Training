#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "ABSPER"

using namespace std;

const int SZ = 5e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int t, n, k;
bool vis[SZ];
vector<int> res;

namespace trau
{
    bool flag = false;

    void recur(int i)
    {
        if(flag) return;
        if(i == n+1)
        {
            for(int x : res) cout << x << " ";
            cout << "Trau \n";
            flag = true;
            return;
        }
        if(i + k <= n && !vis[i + k])
        {
            res.push_back(i + k);
            vis[i + k] = true;
            recur(i + 1);
            res.pop_back();
            vis[i + k] = false;
        }
        if(flag) return;
        if(i - k >= 1 && !vis[i - k])
        {
            res.push_back(i - k);
            vis[i - k] = true;
            recur(i + 1);
            res.pop_back();
            vis[i - k] = false;
        }
    }

    void solve()
    {
        flag = false;
        memset(vis, false, sizeof(vis));
        res.clear();
        recur(1);
        if(flag == false)
        {
            cout << "-1 Trau\n";
        }
    }
}

namespace full
{
    void solve()
    {
        memset(vis, false, sizeof(vis));
        res.clear();
        bool flag = false;
        for(int i = 1; i <= n; i++)
        {
            if(i - k >= 1 && !vis[i - k])
            {
                vis[i - k] = true;
                res.push_back(i - k);
            } else if(i + k <= n && !vis[i + k])
            {
                vis[i + k] = true;
                res.push_back(i + k);
            } else
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            cout << "-1\n";
            return;
        }
        for(int x : res) cout << x << " ";
        cout << "\n";
    }
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        //trau::solve();
        full::solve();
        //cout << '\n' << '\n';
    }
}


/*
6
7 9
5 4
9 1
9 7
10 5
1 0
*/
