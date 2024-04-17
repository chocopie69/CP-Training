#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int MN = 1e5+5;
int n,a[MN],res=0,len=0;

void solve()
{
    for(int i=0;i<n;i++)
    {
        if(i >= 2 && a[i] == a[i-1] && a[i-1] == a[i-2])
        {
            len = 2;
        }
        else
        {
            len++;
        }
        res = max(res,len);
    }
    cout << res;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    solve();
}
