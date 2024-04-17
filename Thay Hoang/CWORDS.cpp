#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CWORDS"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e10, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin);
    //freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll m, cnt[26][26], res1 = 0, res2 = 0, p ,q, r ,s, x, x1, x2;
string a;

int main()
{
    init();
    cin >> m;
    while(m--)
    {
        cin >> a;
        int x = int(a[0]) - int('A');
        int y = int(a[a.length()-1]) - int('A');
        cnt[x][y]++;
        //cout<<x<<" "<<y<<'\n';
    }
    for(int a = 0; a <= 25; a++)
    {
        for(int b = 0; b <= 25; b++)
        {
            for(int c = 0; c <= 25; c++)
            {
                for(int d = 0; d <= 25; d++)
                {
                    p = cnt[a][b]--;
                    q = cnt[a][d]--;
                    r = cnt[b][c]--;
                    s = cnt[d][c]--;
                    x = max(p*q*r*s,0LL);
                    res1 += (x / MOD);
                    res2 += (x % MOD);
                    if(res2 > MOD)
                    {
                        res1 += res2 / MOD;
                        res2 %= MOD;
                    }
                    cnt[a][b]++;
                    cnt[a][d]++;
                    cnt[b][c]++;
                    cnt[d][c]++;
                }
            }
        }
    }
    if(res1 != 0) cout << res1;
    if(res2 != 0 || res1 == 0) cout << res2;
}
