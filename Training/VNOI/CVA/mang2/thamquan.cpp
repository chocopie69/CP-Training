#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXMN = 3*1e4+3;
ll n,m,d[MAXMN],v[MAXMN],res=0;

void solve()
{
    sort(d,d+n,greater<int>());
    sort(v,v+m);
    for(int i=0;i<n;i++)
    {
        res += (d[i]*v[i]);
    }
    cout << res;
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> d[i];
    for(int i=0;i<m;i++) cin >> v[i];
    solve();
}
