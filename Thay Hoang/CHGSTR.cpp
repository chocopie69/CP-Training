#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "CHGSTR"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int n,m;
char last[26];
pair<char,char> a[SZ];
string s;
char x,y;

int main()
{
    init();
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        a[i] = {x,y};
    }
    for(int c = 0; c < 26; c++)
    {
        last[c] = char(c + 'a');
    }
    for(int i = m; i >= 1; i--)
    {
        last[a[i].fi - 'a'] = last[a[i].se - 'a'];
    }
    for(char c : s)
    {
        c = last[c - 'a'];
        cout << c;
    }
}
