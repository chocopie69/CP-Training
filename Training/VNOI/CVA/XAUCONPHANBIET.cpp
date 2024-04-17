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

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n;
string s;

map<string,int> mp;

bool check(int x)
{
    mp.clear();
    for(int i = 1; i <= n - x + 1; i++)
    {
        string cur = s.substr(i, x);
        if(mp.find(cur) != mp.end()) return false;
        mp[cur] = 666;
    }
    return true;
}

int main()
{
    init();
    cin >> n >> s;
    s = " " + s;
    int lo = 1, hi = n, mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(check(mid)) hi = mid-1;
        else lo = mid+1;
    }
    cout << lo;
}
