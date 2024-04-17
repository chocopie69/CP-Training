#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "QUEENS"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, res = 0;
set<pii> chess;

string toString(int x)
{
    ostringstream oss;
    oss << x;
    return oss.str();
}

bool check(pii x)
{
    if(chess.empty())
    {
        return true;
    }
    for(pii i : chess)
    {
        if(i.fi - i.se == x.fi - x.se || i.fi + i.se == x.fi + x.se || i.fi == x.fi || i.se == x.se)
            return false;
    }
    return true;
}

void recur(int i,string s, pii prev)
{
    if(i == n+1)
    {
        res++;
        cout << s << '\n';
        return;
    }
    bool flag = false;
    for(int j = 1; j <= n; j++)
    {
        if(check( {i,j} ) )
        {
            chess.insert({i,j});
            recur(i+1,s + toString(j) + " ", {i,j});
            chess.erase({i,j});
            flag = true;
        }
    }
    if(!flag) return;
}

int main()
{
    init();
    cin >> n;
    recur(1,"",{0,0});
}

