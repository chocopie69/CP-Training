#include <bits/stdc++.h>
using namespace std;

struct Check
{
    int i,j,v;
};

const int LIMIT = 1e5+5;
int n,k,a[LIMIT+2];
Check x[LIMIT+2];

bool cmp(Check x1, Check x2)
{
    return x1.v > x2.v;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NETCARD.INP","r",stdin);
    freopen("NETCARD.OUT","w",stdout);
}

int main()
{
    init();
    fill(a,a+LIMIT,2);
    cin >> n >> k;
    for(int i=1;i<=k;i++)
    {
        int curi,curj,curv;
        cin >> curi >> curj >> curv;
        x[i] = {curi,curj,curv};
    }
    sort(x+1,x+k+1,cmp);
    for(int i=1;i<=k;i++)
    {
        int curi = x[i].i,curj = x[i].j,curv = x[i].v;
        if(curv == 1)
        {
            a[curi] = 1;
            a[curj] = 1;
        }
        else
        {
            if(a[curi] == 1)
            {
                a[curj] = 0;
            }
            if(a[curj] == 1)
            {
                a[curi] = 0;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << a[i] << " ";
    }
}
