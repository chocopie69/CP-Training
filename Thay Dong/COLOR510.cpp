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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int a[11][11];
ll dp[11][11][11][11][11][11], dp2[11][11][11][11][11][11], res;
int maxRect[11][11][11][11][11], s[6], col, h[6], msize, d[6];

void dosmth(int t)
{
    if(t == 1)
    {
//        for(int i = 1; i <= 5; i++)
//        {
//            cout << s[i] << " ";
//        }
//        cout << '\n';
        for(int i = 1; i <= 10; i++)
        {
            int cur = 0;
            for(int j = 1; j <= 5; j++)
            {
                if(s[j] >= i) cur += i;
                else cur = 0;
                maxRect[s[1]][s[2]][s[3]][s[4]][s[5]] = max(maxRect[s[1]][s[2]][s[3]][s[4]][s[5]], cur);
            }
        }
    }
    if(t == 2)
    {
        for(d[1] = 0; d[1] <= 1; d[1]++)
        {
            for(d[2] = 0; d[2] <= 1; d[2]++)
            {
                for(d[3] = 0; d[3] <= 1; d[3]++)
                {
                    for(d[4] = 0; d[4] <= 1; d[4]++)
                    {
                        for(d[5] = 0; d[5] <= 1; d[5]++)
                        {
                            h[1] = d[1] ? s[1] + 1 : 0;
                            h[2] = d[2] ? s[2] + 1 : 0;
                            h[3] = d[3] ? s[3] + 1 : 0;
                            h[4] = d[4] ? s[4] + 1 : 0;
                            h[5] = d[5] ? s[5] + 1 : 0;
                            if(h[1] > 10 || h[2] > 10 || h[3] > 10 || h[4] > 10 || h[5] > 10) continue;
                            if( (h[1] && a[1][col] == 1) || (h[2] && a[2][col] == 1) || (h[3] && a[3][col] == 1) || (h[4] && a[4][col] == 1) || (h[5] && a[5][col] == 1) ) continue;
                            if(maxRect[h[1]][h[2]][h[3]][h[4]][h[5]] <= msize)
                            {
                                dp[col][h[1]][h[2]][h[3]][h[4]][h[5]] += dp[col-1][s[1]][s[2]][s[3]][s[4]][s[5]];
                            }
                            if(maxRect[h[1]][h[2]][h[3]][h[4]][h[5]] < msize)
                            {
                                dp2[col][h[1]][h[2]][h[3]][h[4]][h[5]] += dp2[col-1][s[1]][s[2]][s[3]][s[4]][s[5]];
                            }
                        }
                    }
                }
            }
        }
    }
    if(t == 3)
    {
        res += dp[10][s[1]][s[2]][s[3]][s[4]][s[5]] - dp2[10][s[1]][s[2]][s[3]][s[4]][s[5]];
    }
}

ll solve()
{
    dp[0][0][0][0][0][0] = 1LL;
    dp2[0][0][0][0][0][0] = 1LL;
    for(col = 1; col <= 10; col++)
    {
        for(s[1] = 0; s[1] <= col; s[1]++)
        {
            for(s[2] = 0; s[2] <= col; s[2]++)
            {
                for(s[3] = 0; s[3] <= col; s[3]++)
                {
                    for(s[4] = 0; s[4] <= col; s[4]++)
                    {
                        for(s[5] = 0; s[5] <= col; s[5]++)
                        {
                            dosmth(2);
                        }
                    }
                }
            }
        }
    }
    res = 0;
    for(s[1] = 0; s[1] <= 10; s[1]++)
    {
        for(s[2] = 0; s[2] <= 10; s[2]++)
        {
            for(s[3] = 0; s[3] <= 10; s[3]++)
            {
                for(s[4] = 0; s[4] <= 10; s[4]++)
                {
                    for(s[5] = 0; s[5] <= 10; s[5]++)
                    {
                        dosmth(3);
                    }
                }
            }
        }
    }
    return res;
}

int main()
{
    init();
    cin >> msize;
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            char c;
            cin >> c;
            a[i][j] = int(c) - 48;
            //cout << a[i][j];
        }
    }
    for(s[1] = 0; s[1] <= 10; s[1]++)
    {
        for(s[2] = 0; s[2] <= 10; s[2]++)
        {
            for(s[3] = 0; s[3] <= 10; s[3]++)
            {
                for(s[4] = 0; s[4] <= 10; s[4]++)
                {
                    for(s[5] = 0; s[5] <= 10; s[5]++)
                    {
                        dosmth(1);
                    }
                }
            }
        }
    }
    cout << solve();
}
