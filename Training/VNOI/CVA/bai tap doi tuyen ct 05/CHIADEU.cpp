#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()

#define TASKNAME "chiadeu"

using namespace std;

const int SZ = 1e6+5;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;
const double epsilon = 1e-10;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
double a[SZ];
map<double,ll> mp;
ll res = 0;
vector<double> v;

int main()
{
    init();
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        v.push_back(a[i]);
    }
    v.erase(unique(all(v)),v.end());
    sort(all(v));
    n = v.size() - 1;
    for(int i = 0; i <= n-2; i++)
    {
        for(int j = i+1; j <= n-1; j++)
        {
            res += mp[ (a[i] + a[j]) / 2];
        }
    }
    cout << res;
}
