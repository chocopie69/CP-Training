#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "DEMXAU"

using namespace std;

const int LIMIT = 1e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s;
ll x,cnt=0,res;

int main()
{
    init();
    cin >> s >> x;
    ll n = s.length();
    for(int i = 0; i < n-1; i++)
    {
        if(s[i] == 'a' && s[i+1] == 'b') cnt++;
    }
    res = (cnt*x);
    if(s[n-1] == 'a' && s[0] == 'b') res += x-1;
    cout << res;
}

