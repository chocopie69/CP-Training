#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e6+2;
ll n,a[LIMIT],cnt=0,res=0;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=n-1;i>=0;i--)
    {
        if(a[i] == 0) cnt++;
        else res += cnt;
    }
    cout << res;
}
