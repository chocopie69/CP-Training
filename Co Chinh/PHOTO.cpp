#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e5+2;
int n,a[LIMIT],p[5][LIMIT],k;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PHOTO.INP","r",stdin);
    freopen("PHOTO.OUT","w",stdout);
}

bool cmp(int x,int y)
{
    int cnt = 0;
    for(int i=0;i<5;i++)
    {
        if(p[i][x] < p[i][y]) cnt++;
        if(cnt >= 3) break;
    }
    return cnt >= 3;
}

int main()
{
    init();
    cin >> n;
    for(int i=1;i<=n;i++) a[i] = i;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> k;
            p[i][k] = j;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++) cout << a[i] << " ";
}
