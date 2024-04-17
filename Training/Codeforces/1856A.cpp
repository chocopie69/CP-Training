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

const int SZ = 50+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll t,n,a[SZ];
bool vis[SZ];

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        memset(vis,false,sizeof(vis));
        ll res = 0;
        bool sorted = true;
        ll mn = INFLL;
        for(int i = 1; i <= n; i++)
        {
            if(i > 1 && a[i-1] > a[i]) sorted = false;
        }
        while(!sorted)
        {
            mn = INFLL;
            for(int i = 1; i <= n; i++)
            {
                if(!vis[i])
                    mn = min(mn,a[i]);
            }
            res += mn;
            for(int i = 1; i <= n; i++)
            {
                if(vis[i]) continue;
                if(a[i] == mn)
                {
                    a[i] -= mn;
                    vis[i] = true;
                } else
                {
                    a[i] -= mn;
                }
            }
            sorted = true;
            for(int i = 2; i <= n; i++)
            {
                if(a[i-1] > a[i]) sorted = false;
            }
        }
        cout << res << '\n';
    }
}
