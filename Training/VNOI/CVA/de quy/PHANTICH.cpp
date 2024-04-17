#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NAME"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;

string toString(int x)
{
    ostringstream oss;
    oss << x;
    return oss.str();
}

void recur(int cur, string s, int prev)
{
    if(cur == 0)
    {
        s = s.substr(0,s.length()-1);
        cout << n << "=" + s << '\n';
        return;
    }
    for(int i = prev; i <= cur; i++)
    {
        recur(cur - i, s + toString(i) + "+", i);
    }
}

int main()
{
    init();
    cin >> n;
    recur(n, "", 1);
}

