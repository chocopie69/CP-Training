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

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n, a[SZ], res[SZ], cnt[SZ];

int get(int k)
{
    memset(cnt, 0, sizeof(cnt));
    int j = 1, d = 1, cur = 0;
    for(int i = 1; i <= n; i++)
    {
        int x = a[i];
        if(cnt[x] == 0) cur++;
        if(cur > k)
        {
            while(j < i)
            {
                cnt[a[j]]--;
                //cout << i << " " << j << '\n';
                j++;
            }
//            for(int p = 1; p <= n; p++) cout << cnt[p] << " ";
//            cout << '\n';
            cur = 1;
            d++;
        }
        cnt[x]++;
    }
    res[k] = d;
    return d;
}

void calc(int lo, int hi)
{
    if(lo > hi) return;
    int x = get(lo);
    if(x == get(hi))
    {
        for(int i = lo + 1; i < hi; i++) res[i] = x;
        return;
    }
    int mid = (lo + hi) / 2;
    calc(lo + 1, mid);
    calc(mid + 1, hi - 1);
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    //cout << get(1) << '\n';
    calc(1, n);
    for(int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
}
