#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second

#define TASKNAME "LAUGH"

using namespace std;

const int SZ = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, f[SZ], res = 0;
string s,p[SZ];
bool vis[SZ];
vector<int> d;
set<string> a[SZ];

int main()
{
    init();
    cin >> n >> s;
    memset(vis,false,sizeof(vis));
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
        int len = p[i].length();
        if(!vis[len]) d.push_back(len);
        vis[len] = true;
        a[len].insert(p[i]);
    }
    s = " " + s;
    f[0] = 0;
    for(int i = 0; i < s.length(); i++)
    {
        for(int len : d)
        {
            int j = i+len;
            if(j >= s.length()) continue;
            string cur = s.substr(i+1,len);
            if(a[len].find(cur) != a[len].end())
            {
                f[j] = max(f[j],f[i] + len);
            }
        }
    }
    for(int i = 1; i < s.length(); i++)
    {
        res = max(res,f[i]);
    }
    cout << res;
}

/*
2
ahahhahaah
a
ha
*/

