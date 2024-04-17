#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;
int a[510][510], n, m, k;
void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
namespace trau
{
    struct hcn
    {
        int x1, y_1, x2, y2;
        hcn(int _x1 = 0, int _y_1 = 0, int _x2 = 0, int _y2 = 0)
        {
            x1 = _x1;
            y_1 = _y_1;
            x2 = _x2;
            y2 = _y2;
        }
    };
    struct ans_val
    {
        hcn x;
        int y;
        int area;
    };
    bool cmp (ans_val a, ans_val b)
    {
        return a.area < b.area;
    }
    hcn c[40];
    void solve()
    {
        for(int i = 1; i <= 30; i++)
        {
           c[i] = {INF, INF, 0, 0};
        }

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                c[a[i][j]].x1 = min(c[a[i][j]].x1, i);
                c[a[i][j]].y_1 = min(c[a[i][j]].y_1, j);
                c[a[i][j]].x2 = max(c[a[i][j]].x2, i);
                c[a[i][j]].y2 = max(c[a[i][j]].y2, j);
            }
        }
        vector < ans_val > ans;
        hcn tmp = {INF, INF, 0, 0};
        for(int i = 1; i <= 30; i++)
        {
            if(c[i].x1 != INF && c[i].y_1 != INF && c[i].x2 != 0 && c[i].y2 != 0)
                {
                   int d = c[i].x2 - c[i].x1 + 1;
                   int r = c[i].y2 - c[i].y_1 + 1;
                   ans.push_back({c[i], i, d*r});
                }
        }
        cout << ans.size() << '\n';
        sort(ans.begin(), ans.end(), cmp);
        for(auto j: ans)
        {
            hcn i = j.x;
            cout << i.x1 << ' ' << i.y_1 << ' ' << i.x2 << ' ' << i.y2 << ' ' << j.y << '\n';
        }

    }
}
int main()
{
    init();
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
    {
        cin >> a[i][j];
    }
    trau::solve();
}
