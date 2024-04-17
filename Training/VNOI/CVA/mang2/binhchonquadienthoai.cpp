#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e5+2;
int n,a[LIMIT],cnt[LIMIT],maxCnt=0;

void solve()
{
    for(int i=0;i<n;i++)
    {
        cnt[a[i]]++;
        maxCnt = max(maxCnt,cnt[a[i]]);
    }
    for(int i=1;i<=1000;i++)
    {
        if(cnt[i] == maxCnt) cout << i << endl;
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
