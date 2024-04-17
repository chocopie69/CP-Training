#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "SM"

using namespace std;

const int SZ = 1e6+5, base = 311;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s,t;
ll f[SZ], cnt = 0, lenS, lenT;
vector<int> res;

void kmpS()
{
    f[1] = 0;
    ll q = 0;
    for(int i = 2; i <= lenS; i++)
    {
        while(q > 0 && s[q+1] != s[i])
        {
            q = f[q];
        }
        if(s[q+1] == s[i]) q++;
        f[i] = q;
    }
}

int main()
{
    init();
    cin >> s >> t;
    lenS = s.length();
    lenT = t.length();
    s = " " + s;
    t = " " + t;
    kmpS();
    ll j = 0;
    for(int i = 1; i <= lenT; i++)
    {
        while(j > 0 && s[j+1] != t[i])
        {
            j = f[j];
        }

        if(s[j+1] == t[i]) j++;
        if(j == lenS)
        {
            cnt++;
            res.push_back(i-lenS);
            j = f[j];
        }
    }
    cout << cnt << '\n';
    for(int i : res)
    {
        cout << i << " ";
    }
}

