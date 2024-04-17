#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct CowPair
{
    int a,b;
};

bool cmp(CowPair x, CowPair y)
{
    return (x.b < y.b);
}

const int MAXK = 1005;
int n,k,res=2,last;
CowPair cow[MAXK];

void solve()
{
    sort(cow,cow+k,cmp);
    last = cow[0].b-1;
    for(int i=1;i<k;i++)
    {
        if(cow[i].b > n) break;
        if(cow[i].a > last)
        {
            res++;
            last = cow[i].b-1;
        }
    }
    cout << res;
}

int main()
{
    cin >> n >> k;
    for(int i=0;i<k;i++)
    {
        cin >> cow[i].a >> cow[i].b;
        if(cow[i].a > cow[i].b) swap(cow[i].a,cow[i].b);
    }
    solve();
}
