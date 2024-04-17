#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e5+2;
int n,q,a[MAXN],sum[MAXN];

int main()
{
    memset(sum,0,sizeof(sum));
    cin >> n >> q;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    int x,y;
    for(int i=1;i<=q;i++)
    {
        cin >> x >> y;
        cout << sum[y] - sum[x-1] << endl;
    }
}
