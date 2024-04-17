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

const int SZ = 4e5+5, BS = 500;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

int n, a[SZ], cnt[SZ];
vector<int> cprs, v1, v2, pos[SZ];
ll dp[SZ], res = 0;

ll calc(ll i, ll j, ll k){
    ll l = k - i, r = k;
    k = max(0LL, r - max(j + 1, l - 1));
    l = max(l, 0LL);
    r = min(r, j + 1);
    if (l > r) return k * (j + 1);
    return 1LL * (l + r) * (r - l + 1) / 2 + k * (j + 1);
}

void solve2(int c){
    for (int i = 0; i < pos[c].size(); ++i){
        for (int j = i; j < pos[c].size(); ++j){
            int l = i ? pos[c][i - 1] : 0;
            int r = (j + 1 == pos[c].size()) ? n + 1 : pos[c][j + 1];
            int k = (j - i + 1) - (pos[c][j] - pos[c][i] - j + i);
            res += calc(pos[c][i] - l - 1, r - pos[c][j] - 1, k);
        }
    }
}

void solve1(int c){
    memset(dp, 0, sizeof(dp));
    int cur = n + 4;
    dp[cur] = 1;
    for (int i = 1; i <= n; ++i){
        if (a[i] == c){
            ++cur;
            dp[cur] += dp[cur - 1];
        }
        else{
            dp[cur] -= dp[cur - 1];
            --cur;
        }
        res += dp[cur - 1];
        ++dp[cur];
    }
}

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cprs.pb(a[i]);
    }
    sort(all(cprs));
    for(int i = 1; i <= n; i++)
    {
        a[i] = lwb(all(cprs), a[i]) - cprs.begin() + 1;
        cnt[a[i]]++;
        pos[a[i]].pb(i);
    }
    for(int i = 1; i <= n; i++)
    {
        if(pos[i].empty()) continue;
        if(cnt[i] >= BS) solve1(i);
        else solve2(i);
    }
    cout << res;
}

