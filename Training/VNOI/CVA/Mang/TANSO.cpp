#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
int n,a[maxN];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int cnt = 1;
    if(n == 1) cout << a[0] << " " << 1;
    for(int i=1;i<n;i++)
    {
        if(a[i] == a[i-1])
        {
            cnt++;
        } else
        {
            cout << a[i-1] << " " << cnt << endl;
            cnt = 1;
        }
        if(i == n-1) cout << a[i] << " " << cnt;
    }
}
