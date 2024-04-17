#include <bits/stdc++.h>
#define ll long long
using namespace std;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PRJCHAIN.INP","r",stdin);
    freopen("PRJCHAIN.OUT","w",stdout);
}

struct Project
{
    ll in,out,money,index;
};

bool cmp(Project x,Project y)
{
    if(x.money*y.money < 0) return x.money > y.money;
    if(x.money > 0 && y.money > 0) return x.in < y.in;
    if(x.money < 0 && y.money < 0) return x.out > y.out;
}

const int LIMIT = 1e5+2;
int n;
ll res=0;
Project a[LIMIT];

int main()
{
    //init();
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i].in;
    }
    for(int i=0;i<n;i++)
    {
        cin >> a[i].out;
        a[i].money = a[i].out - a[i].in;
        a[i].index = i+1;
    }
    sort(a,a+n,cmp);
    ll moneyNeed=0;
    for(int i=0;i<n;i++)
    {
        moneyNeed -= a[i].in;
        if(moneyNeed < 0)
        {
            res -= moneyNeed;
            moneyNeed = 0;
        }
        moneyNeed += a[i].out;
    }
    cout << res;
    //for(int i=0;i<n;i++) cout << a[i].index << " ";
}
