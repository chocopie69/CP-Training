#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "rusdoll"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,a[SZ],cnt[SZ];
vector<int> v, k1, k2;

signed main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }
    v.erase(unique(all(v)),v.end());
    sort(all(v));
    for(int i = 1; i <= n; i++)
    {
        a[i] = (lower_bound(all(v),a[i]) - v.begin() + 1);
    }
    for(int k = n/2; k >= 1; k--)
    {
        for(int i = 1; i <= k; i++)
        {
            cnt[a[i]]++;
        }
        for(int i = 1; i <= n; i++)
        {
            while(cnt[i] > 0)
            {
                k1.push_back(i);
                cnt[i]--;
            }
        }
        for(int i = k+1; i <= k*2; i++)
        {
            cnt[a[i]]++;
        }
        for(int i = 1; i <= n; i++)
        {
            while(cnt[i] > 0)
            {
                k2.push_back(i);
                cnt[i]--;
            }
        }
        bool flag = false;
        while(!k1.empty() && !k2.empty())
        {
            if(k1.back() >= k2.back()) flag = true;
            k1.pop_back();
            k2.pop_back();
        }
        if(!flag)
        {
            cout << k;
            exit(0);
        }
    }
    cout << -1;
}

/*
10
2 1 4 2 3 2 4 5 2 3
*/
