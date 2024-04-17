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

int n,m, idx = 0;
map<string,int> mp;

string states[SZ];

void recur(int i, string s, int prev)
{
    if(i == m+1)
    {
        ++idx;
        states[idx] = s;
        mp[s] = idx;
    }
    if(prev != 2) recur(i+1, s + "1" ,1);
    if(prev != 1) recur(i+1, s + "2", 2);
    recur(i+1,s + "0",0);
}

void build()
{
    for(int i = 1; i <= idx; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(states[i])
        }
    }
}

int main()
{
    init();
    while(cin >> n)
    {
        cin >> m;
        if(n == -1) break;
        if(n < m) swap(n,m);
    }
}
