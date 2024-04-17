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

string s,t;
int n,m;

int main()
{
    init();
    cin >> s >> t;
    n = s.length();
    m = t.length();
    s = " " + s;
    t = " " + t;
    int len = __gcd(n,m);
    string q;
    if(s.substr(1,len) == t.substr(1,len))
    {
        q = s.substr(1,len);
    } else
    {
        cout << "NO";
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        if(s[i] != s[ (i-1) % len + 1 ])
        {
            cout << "NO";
            return 0;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(t[i] != t[ (i-1) % len + 1 ])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << q;
}
