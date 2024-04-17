#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "NAME"

using namespace std;

const int SZ = 2e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-3;

void init()
{
    ///freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m, res = 0, maxV[SZ];
pii a[SZ];
vector<pii> sum1, sum2;

void recur1(int i, pii sum)
{
    if(i == n/2)
    {
        sum1.push_back(sum);
        return;
    }
    recur1(i+1,{sum.fi+a[i+1].fi,sum.se+a[i+1].se});
    recur1(i+1,sum);
}

void recur2(int i, pii sum)
{
    if(i == n)
    {
        sum2.push_back(sum);
        return;
    }
    recur2(i+1,{sum.fi+a[i+1].fi,sum.se+a[i+1].se});
    recur2(i+1,sum);
}

int main()
{
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    recur1(0,{0,0});
    recur2(n/2,{0,0});
    sort(all(sum1));
    sort(all(sum2));
    for(int i = 0; i < sum2.size(); i++)
    {
        maxV[i] = (i == 0 ? sum2[i].se : max(maxV[i-1],sum2[i].se));
    }
    int j = sum2.size()-1;
    for(int i = 0; i < sum1.size(); i++)
    {
        while(j > 0 && sum1[i].fi + sum2[j].fi > m) j--;
        if(sum1[i].fi + sum2[j].fi <= m)
        {
            res = max(res, sum1[i].se + maxV[j]);
        }
    }
    cout << res;
}
