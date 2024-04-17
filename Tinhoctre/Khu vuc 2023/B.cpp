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

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,a[SZ];
set<int> s;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int x = 0; x < n; x++)
    {
        if(x == 0)
        {
            cout << -1 << '\n';
            continue;
        }
        int k = 0;
        s.clear();
        for(int i = 1; i <= n; i++)
        {
            if(a[i] <= x)
            {
                s.insert(a[i]);
                if(s.size() == x+1)
                {
                    s.clear();
                    s.insert(a[i]);
                    k++;
                }
            }
            if(i == n) k++;
        }
        cout << k << '\n';
    }
}
