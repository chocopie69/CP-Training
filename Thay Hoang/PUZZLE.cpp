#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "PUZZLE"

using namespace std;

const int SZ = 1e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m;
char c[SZ][SZ];
vector<string> v;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        string s = "";
        for(int j = 1; j <= m; j++)
        {
            if(c[i][j] == '#' || j == m)
            {
                if(j == m && c[i][j] != '#') s += c[i][j];
                if(s != "")
                {
                    v.push_back(s);
                    //cout << s << " " << i << " " << j << '\n';
                }
                s = "";
            } else if(c[i][j] != '#')
            {
                s += c[i][j];
            }
        }
    }
    for(int j = 1; j <= m; j++)
    {
        string s = "";
        for(int i = 1; i <= n; i++)
        {
            if(c[i][j] == '#' || i == n)
            {
                if(i == n && c[i][j] != '#') s += c[i][j];
                if(s != "")
                {
                    v.push_back(s);
                    //cout << s << " " << i << " " << j << '\n';
                }
                s = "";
            } else if(c[i][j] != '#')
            {
                s += c[i][j];
            }
        }
    }
    sort(all(v),greater<string>());
    cout << v[0];
}
