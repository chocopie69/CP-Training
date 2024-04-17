#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e5+2;
int n,a[LIMIT],cnt[LIMIT],res=0;

void solve()
{
    for(int i=0;i<n;i++)
    {
        cnt[a[i]]++;
    }
    for(int i=1;i<=1000;i++)
    {
        if(cnt[i] > 0) res++;
    }
    cout << res << endl;
    for(int i=1;i<=1000;i++)
    {
        if(cnt[i] > 0) cout << i << " ";
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    solve();
}
