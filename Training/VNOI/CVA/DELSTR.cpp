#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "DELSTR"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int m,k, n, res = INF, cnt[26];
string s;
vector<int> vec;
bool vis[SZ];

int main()
{
    init();
    cin >> m >> k >> s;
    n = s.length();
    s = " " + s;
    for(int i = 1; i <= n; i++)
    {
        int x = int(s[i]) - 'A';
        if(vis[x]) continue;
        vis[x] = true;
        vec.push_back(x);
    }
    int lo = 1;
    for(int hi = 1; hi <= n; hi++)
    {
        cnt[int(s[hi]) - 'A']++;
        while(lo < hi && cnt[ int(s[lo]) - 'A' ] > k )
        {
            cnt[ int(s[lo]) - 'A' ]--;
            lo++;
        }
        bool flag = false;
        for(int x : vec)
        {
            if(cnt[x] < k) flag = true;
        }
        if(!flag) res = min(res, hi - lo + 1 - m*k);
    }
    cout << res;
}

/*
3 2
ABBABCABBCCCBA
*/
