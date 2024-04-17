#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e5+2;
long long n,s,a[LIMIT],cnt[LIMIT],res=0;

int main()
{
    memset(cnt,0,sizeof(cnt));
    cin >> n >> s;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        res += cnt[s-a[i]];
        cnt[a[i]]--;
    }
    cout << res;
}
