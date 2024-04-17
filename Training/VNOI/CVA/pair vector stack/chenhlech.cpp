#include <bits/stdc++.h>
using namespace std;

pair<int,int> a[1002];
int n,cnt[1002],res,maxExist=0;

int main()
{
    memset(cnt,0,sizeof(cnt));
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i].first >> a[i].second;
        cnt[abs(a[i].first - a[i].second)]++;;
    }
    for(int i=0;i<=1000;i++)
    {
        if(cnt[i] > maxExist)
        {
            maxExist = cnt[i];
            res = i;
        }
    }
    cout << res << endl;
    for(int i=0;i<n;i++)
    {
        if(abs(a[i].second-a[i].first) == res) cout << a[i].first << " " << a[i].second << '\n';
    }
}
