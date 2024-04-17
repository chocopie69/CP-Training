#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e5+5;
int n;
ll a[LIMIT],sum[LIMIT],cnt=0,res=0;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("COINCOL.INP","r",stdin);
    freopen("COINCOL.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(i == n || res + a[i] < a[i+1])
        {
            cnt++;
            res += a[i];
        }
    }
    cout << cnt << " " << res;
}
