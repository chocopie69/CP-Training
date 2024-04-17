#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "XAUCHUNGMAX"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

string x, y, res = "";
int n, m;
set<string> s;

bool isNum(char c)
{
    return int(c) >= int('0') && int(c) <= int('9');
}

string better(string a, string b)
{
    while(a.size() > 0 && a[0] == '0') a.erase(a.begin());
    while(b.size() > 0 && b[0] == '0') b.erase(b.begin());
    if(a.size() > b.size()) return a;
    if(a.size() < b.size()) return b;
    if(a < b) swap(a,b);
    return a;
}

int main()
{
    init();
    cin >> x >> y;
    n = x.length();
    m = y.length();
    x = " " + x;
    y = " " + y;
    for(int i = 1; i <= n; i++)
    {
        string cur = "";
        int j = i;
        while(isNum(x[j]))
        {
            cur += x[j];
            j++;
            s.insert(cur);
            //cout << cur << " x\n";
            if(j > n || !isNum(x[j]))
            {
                break;
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        string cur = "";
        int j = i;
        while(isNum(y[j]))
        {
            cur += y[j];
            j++;
            //cout << cur << " y\n";
            if(s.find(cur) != s.end()) res = better(res,cur);
            if(j > m || !isNum(y[j]) )
            {
                break;
            }
        }
    }
    cout << res;
}

/*
ab123abcba57
cba12abcbad23
*/
