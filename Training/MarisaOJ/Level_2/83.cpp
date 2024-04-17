#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define lwb lower_bound
#define upb upper_bound

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

string x,y;
int n,m;
vector<int> pos[SZ];
ll res = 0;

int main()
{
    init();
    cin >> x >> y;
    n = x.length(), m = y.length();
    for(int i = 0; i < n; i++)
    {
        int c = x[i] - 'a';
        pos[c].pb(i);
    }
    for(int i = 0; i < m; i++)
    {
        int c = y[i] - 'a';
        int lo = i, hi = n-1 - m + 1 + i;
        int pos1 = lwb(all(pos[c]),lo) - pos[c].begin(), pos2 = upb(all(pos[c]),hi) - pos[c].begin() - 1;
        res += 1LL*pos2-pos1+1;
    }
    cout << res;
}

