#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e5+5;
int n;
string a[LIMIT];

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAXNUM.INP","r",stdin);
    freopen("MAXNUM.OUT","w",stdout);
}

bool cmp(string x,string y)
{
    return x+y > y+x;
}

int main()
{
    init();
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++) cout << a[i];
}
