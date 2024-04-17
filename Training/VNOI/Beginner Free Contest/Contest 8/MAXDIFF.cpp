#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1002;
int n,a[LIMIT],res=-INT_MAX;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    init();
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=1;i<n-1;i++)
    {
        res = max(res,a[i+1]-a[i-1]);
    }
    cout << res;
}
