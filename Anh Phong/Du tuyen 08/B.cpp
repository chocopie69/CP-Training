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

#define TASKNAME "NAME"

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

const int SZ = 2e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m,k;
bitset<2002> a[SZ];

int main()
{
    init();
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].set(y);
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            bitset<2002> cur = a[i] & a[j];
            if(cur.count() > 1)
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}

