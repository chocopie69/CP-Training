#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "NAME"

using namespace std;

const int SZ = 2e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int t,n,k,a[SZ], b[SZ],pre;
vector<int> val[SZ], id[SZ];
string res;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        res = "YES";
        pre = -INF;
        cin >> n >> k;
        for(int i = 0; i <= k; i++)
        {
            val[i].clear();
            id[i].clear();
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = 0;
            int g = max(i % k, k - i % k);
            val[g].push_back(a[i]);
            id[g].push_back(i);
        }
        for(int i = 0; i <= k; i++)
        {
            if(val[i].empty()) continue;
            sort(val[i].begin(), val[i].end());
            for(int j = 0; j < val[i].size(); j++)
            {
                b[id[i][j]] = val[i][j];
            }
        }
        cout << (is_sorted(b+1,b+n+1) ? "YES" : "NO") << '\n';
    }
}

