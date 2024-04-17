#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;
int n,a[maxN],cnt[maxN],pos=0;

int main()
{
    cin >> n;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i] > n || a[i] < 1) pos = i+1;
        else {
            if(cnt[a[i]] > 0) pos = i+1;
            cnt[a[i]]++;
        }
    }
    cout << pos << " ";
    for(int i=1;i<=n;i++)
    {
        if(cnt[i] == 0) cout << i;
    }
}

