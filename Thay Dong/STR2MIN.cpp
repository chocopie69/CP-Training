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

string s;

vector<int> v[26];

string str2min(const string &s, int l, int r) {
    if (l == r) {
        return "";
    }
    string min_ans = "";
    for (int i = 0; i <= 25; i++) {
        int pos = upper_bound(all(v[i]),r-1) - v[i].begin() - 1;
        if(pos < 0 || v[i][pos] < l) continue;
        return s[v[i][pos]] + str2min(s, l, v[i][pos]) + str2min(s, v[i][pos] + 1, r);
    }
    return "";
}

int main()
{
    init();
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        v[s[i] - 'a'].push_back(i);
    }
    cout << str2min(s, 0, s.size());
}
