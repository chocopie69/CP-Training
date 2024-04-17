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

int t, n, a[SZ], cnt[SZ], suffix[SZ], res;
set<int> s;
vector<int> v;

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        res = 0;
        cin >> n;
        memset(cnt,0,sizeof(cnt));
        v.clear();
        s.insert(0);
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s.insert(i);
        }
        for(int i = n; i >= 1; i--)
        {
            s.erase(a[i]);
            suffix[i] = *s.begin();
        }
        for(int i = 0; i <= n; i++)
        {
            s.insert(i);
        }
        int prev = 1;
        for(int i = 1; i <= n; i++)
        {
            s.erase(a[i]);
            cnt[a[i]]++;
            if(*s.begin() == suffix[prev])
            {
                v.push_back(suffix[prev]);
                while(prev <= i)
                {
                    cnt[a[prev]]--;
                    if(cnt[a[prev]] == 0) s.insert(a[prev]);
                    prev++;
                }
                res++;
            }
        }
        cout << res << '\n';
        for(int x : v)
        {
            cout << x << " ";
        }
        cout << '\n';
    }
}
