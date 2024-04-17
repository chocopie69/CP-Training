#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "TKXAU"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

string s;
int n, res = 1;
set<int> d;

int main()
{
    init();
    cin >> s;
    n = s.length();
    s = " " + s;
    for(int i = 1; i <= n; i++)
    {
        d.insert(int(s[i]));
    }
    for(int i = 2; i < n; i++)
    {
        int cur = 1, j = i-1, k = i+1;
        while(s[j] == s[k] && j >= 1 && k <= n)
        {
            cur += 2;
            res = max(res, cur);
            j--;
            k++;
        }
        if(s[i] != s[i+1]) continue;
        cur = 2, j = i-1, k = i+2;
        while(s[j] == s[k] && j >= 1 && k <= n)
        {
            cur += 2;
            res = max(res, cur);
            j--;
            k++;
        }
    }
    cout << d.size() << '\n' << res;
}
