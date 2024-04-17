#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
int n,s,a[maxN];

int main()
{
    cin >> n >> s;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(s >= a[i])
        {
            s += a[i];
            cnt++;
        }
    }
    cout << cnt;
}

