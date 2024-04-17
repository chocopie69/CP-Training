#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Line
{
    ll left,right;
};

const int LIMIT = 200005;
ll n,res=0;
Line a[LIMIT];

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("VISIT.INP","r",stdin);
    freopen("VISIT.OUT","w",stdout);
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].left >> a[i].right;
    }
    a[n+1] = {6,6};
    ll curX = 1;
    for(int i=1;i<=n;i++)
    {
        if(curX <= a[i].left)
        {
            res += a[i].right - curX + 1;
            curX = a[i].right;
        }
        else if(curX >= a[i].right)
        {
            res += curX - a[i].left + 1;
            curX = a[i].left;
        }
        else
        {
            if(i < n)
            {
                res += min()
            }
        }
    }
    res += (n-curX-1);
    cout << res;
}
