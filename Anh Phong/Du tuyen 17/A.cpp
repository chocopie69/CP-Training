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

const int SZ = 2e3+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n,m, cnt[SZ][SZ], lo[SZ], hi[SZ];
char a[SZ][SZ];
vector<int> st1, st2;
ll res = 0;

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int j = 1; j <= m; j++)
    {
        cnt[0][j] = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i][j] == '.') cnt[i][j] = cnt[i-1][j] + 1;
            else cnt[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        st1.clear();
        st2.clear();
        st1.pb(0);
        st2.pb(m+1);
        for(int j = m; j >= 1; j--)
        {
            while(st2.size() > 1 && cnt[i][st2.back()] > cnt[i][j]) st2.pop_back();
            hi[j] = st2.back();
            st2.pb(j);
        }
        for(int j = 1; j <= m; j++)
        {
            while(st1.size() > 1 && cnt[i][st1.back()] >= cnt[i][j]) st1.pop_back();
            ll x = j - st1.back(), y = hi[j] - j;
            res += (cnt[i][j] * (cnt[i][j] + 1) / 2) * ( x * y * (x+y) / 2 );
            st1.pb(j);
        }
    }
    cout << res;
}

