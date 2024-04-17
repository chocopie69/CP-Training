#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "LISLCS"

using namespace std;

const int SZ = 5e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m, a[SZ], b[SZ], v = 0;

namespace sub1
{
    vector<vector<int>> vec1, vec2;
    vector<int> cur;
    int lis[SZ], res = 0, mx = 0;

    void recur1(int pos)
    {
        if(pos == n+1)
        {
            vec1.push_back(cur);
            return;
        }
        cur.push_back(a[pos]);
        recur1(pos + 1);
        cur.pop_back();
        recur1(pos + 1);
    }

    void recur2(int pos)
    {
        if(pos == m+1)
        {
            vec2.push_back(cur);
            return;
        }
        cur.push_back(b[pos]);
        recur2(pos + 1);
        cur.pop_back();
        recur2(pos + 1);
    }

    void solve()
    {
        recur1(1);
        cur.clear();
        recur2(1);
        for(int i = 0; i < vec1.size(); i++)
        {
            for(int j = 0; j < vec2.size(); j++)
            {
                if(vec1[i].size() != vec2[j].size()) continue;
                int p = vec1[i].size();
                lis[0] = -INF;
                for(int k = 1; k <= p; k++) lis[k] = INF;
                bool flag = false;
                for(int k = 0; k < p; k++)
                {
                    if(vec1[i][k] != vec2[j][k]) flag = true;
                }
                if(flag) continue;
                for(int k = 0; k < p; k++)
                {
                    int pos = lower_bound(lis, lis + p + 1, vec1[i][k]) - lis;
                    lis[pos] = vec1[i][k];
                    int oldres = res;
                    if(p == mx) res = max(res, pos);
                    if(p > mx)
                    {
                        mx = p;
                        res = pos;
                    }
//                    if(res != oldres)
//                    {
//                        for(int x : vec1[i]) cout << x << " ";
//                        cout << "- ";
//                        for(int x : vec2[j]) cout << x << " ";
//                        cout << '\n';
//                    }
                }
            }
        }
        cout << res;
    }
}

namespace sub2
{
    int res = 0, mx = 0;
    vector<int> dp[1002][1002];
    int lcs[1002][1002];

    void solve()
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(a[i] == b[j])
                {
                    dp[i][j] = dp[i-1][j-1];
                    if(dp[i][j].empty() || a[i] > dp[i][j].back())
                    {
                        dp[i][j].push_back(a[i]);
                    } else
                    {
                        int pos = lower_bound(all(dp[i][j]),a[i]) - dp[i][j].begin();
                        dp[i][j][pos] = a[i];
                    }
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                } else
                {
                    if(lcs[i-1][j] > lcs[i][j-1])
                    {
                        dp[i][j] = dp[i-1][j];
                        lcs[i][j] = lcs[i-1][j];
                    } else if(lcs[i][j-1] > lcs[i-1][j])
                    {
                        dp[i][j] = dp[i][j-1];
                        lcs[i][j] = lcs[i][j-1];
                    } else
                    {
                        dp[i][j] = dp[i-1][j];
                        for(int k = 0; k < dp[i][j-1].size(); k++)
                        {
                            if(k < dp[i][j].size())
                                dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k]);
                            else
                                dp[i][j].push_back(dp[i][j-1][k]);
                        }
                        lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                    }
                }
                int oldres = res;
                if(lcs[i][j] == mx) res = max(res, (int)dp[i][j].size());
                if(lcs[i][j] > mx)
                {
                    mx = lcs[i][j];
                    res = dp[i][j].size();
                }
                if(true)
                {
                    //cout << i << " " << j << " " << dp[i][j].size() << " " << lcs[i][j] << " " << dp[i][j][ (int) dp[i][j].size() - 1 ] << '\n';
                }
            }
        }
        cout << res;
    }
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v = max(v, a[i]);
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> b[i];
        v = max(v, b[i]);
    }
    if(n <= 10 && m <= 10)
        sub1::solve();
    else if(n <= 500 && m <= 500 && v <= 500)
        sub2::solve();
    else
        sub2::solve();
}

/*
10 11
1 2 3 4 9 5 8 6 10 7
9 10 5 8 6 7 1 2 3 4 5
*/
