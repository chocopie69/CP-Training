#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e3+5, SZ2 = 25;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m, dp[SZ];
pair<vector<int>,int> a[SZ];
bool connected[SZ][SZ];
vector<int> res[SZ];

bool cmp(pair<vector<int>,int> x, pair<vector<int>,int> y)
{
    for(int i = 0; i < m; i++)
    {
        if(x.first[i] < y.first[i]) return true;
        if(x.first[i] > y.first[i]) return false;
    }
    return true;
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            a[i].first.push_back(x);
        }
        a[i].second = i;
        sort(all(a[i].first));
    }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            //cout << a[i].first[j] << " ";
        }
        //cout << '\n';
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            int cur = 0;
            bool lmao = true;
            for(int k = 0; k < m; k++)
            {
                if(a[i].first[k] > a[j].first[k])
                {
                    lmao = false;
                    break;
                }
            }
            connected[i][j] = lmao;
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            //cout << i << " - " << j << " " << connected[i][j] << '\n';
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for(int j = 1; j < i; j++)
        {
            if(!connected[j][i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
        res[dp[i]].push_back(i);
        mx = max(mx, dp[i]);
        //cout << dp[i] << ' ' << i << '\n';
    }
    cout << mx << '\n';
    for(int i = 1; i <= n; i++)
    {
        if(res[i].size() == 0) continue;
        cout << res[i].size() << " ";
        for(int x : res[i]) cout << a[x].second << " ";
        cout << '\n';
    }
}
