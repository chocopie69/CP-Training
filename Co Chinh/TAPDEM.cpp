#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<long long, long long>

#define TASKNAME "TAPDEM"

using namespace std;

const int SZ = 1e5+5, MAXA = 5e4+2;
const ll INF = INT_MAX / 2, MOD = 1e9+7, INFLL = 2e18;

void init()
{
    //freopen(TASKNAME".INP","r",stdin); freopen(TASKNAME".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,q,a[SZ], l, r , x;
vector<int> v[MAXA];

int main()
{
    init();
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
    while(q--)
    {
        cin >> l >> r >> x;
        int posL = lower_bound(v[x].begin(),v[x].end(), l) - v[x].begin(),
            posR = upper_bound(v[x].begin(),v[x].end(), r) - v[x].begin() - 1;
        cout << max(posR-posL+1,0) << '\n';
    }
}

