#include <bits/stdc++.h>
using namespace std;

struct Pair
{
    int value, index;
};

const int LIMIT = 2*1e5+3;
map<int,int> m1,m2;
int n,m,k,kq[LIMIT],f[LIMIT],g[LIMIT];

Pair a[LIMIT];

bool cmp(Pair x, Pair y)
{
    if(x.value != y.value) return x.value < y.value;
    return x.index < y.index;
}

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("EQVAL.INP","r",stdin);
    freopen("EQVAL.OUT","w",stdout);
}

void buildResArray()
{
    stable_sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        m1[a[i].value]++;
        f[i] += m1[a[i].value];
    }
    for(int i=n-1;i>=0;i--)
    {
        g[i] += m2[a[i].value];
        m2[a[i].value]++;
    }
    kq[a[0].index] = g[0];
    for(int i=1;i<n;i++)
    {
        kq[a[i].index] = kq[a[i-1].index] + g[i] - f[i];
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> a[i].value;
        a[i].index = i;
    }
    a[n] = {INT_MAX,n};
    buildResArray();
    while(m--)
    {
        cin >> k;
        cout << kq[k] << '\n';
    }
}

/*
9 9
0 1 0 2 1 3 0 3 4
0
1
2
3
4
5
6
7
8
*/
