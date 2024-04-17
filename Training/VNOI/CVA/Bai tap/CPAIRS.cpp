#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "CPAIRS"

using namespace std;

const int LIMIT = 3e5+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

map<ll,ll> mp, cnt;
ll n,p,k,a[LIMIT], res = 0;

int main()
{
    init();
    cin >> n >> p >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        //if(a[i] == 0) continue;
        cnt[a[i]]++;
        ll curMod = (a[i] % p * (((a[i]*a[i]*a[i] - k) % p + p) % p) ) % p;
        //curMod = (curMod + p) % p;
        mp[curMod]++;
    }
    for(int i = 1; i <= n; i++)
    {
        //if(a[i] == 0) continue;
        ll curMod = (a[i] % p * (((a[i]*a[i]*a[i] - k) % p + p) % p) ) % p;
        //curMod = (curMod + p) % p;
        mp[curMod]--;
        res += max(0LL,mp[curMod]);
    }
    cout << res;
}

