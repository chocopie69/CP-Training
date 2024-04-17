#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "EDITOR"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
}

int t, z[SZ], n;
string s;

void calcZ()
{
    memset(z, 0, sizeof(z));
    int lo = 0, hi = 0;
    for(int i = 1; i < n; i++)
    {
        if(i <= hi)
        {
            z[i] = min(hi - i + 1, z[i - lo]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if(i + z[i] - 1 > hi)
        {
            hi = i + z[i] - 1;
        }
    }
    for(int i = 0; i < n; i++)
    {
        z[i] = min(z[i], i);
        //cout << i << " " << z[i] << '\n';
    }
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        cin >> s;
        n = s.length();
        calcZ();
        int i = 0, mx = -1, res = 0;
        for(int x = 0; x < n; x++)
        {
            if(x <= mx) continue;
            res++;
            while(i <= x)
            {
                mx = max(mx, max(i, i + z[i] - 1));
                i++;
            }
        }
        cout << res << '\n';
    }
}

/*
3
eeeeeeeee
abaabcabaabaabc
xooxoxxooxox
*/
