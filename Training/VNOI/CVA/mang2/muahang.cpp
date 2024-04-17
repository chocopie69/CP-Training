#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e4+2;

struct Shop
{
    int amount,price,index,bought;
};

int m,n,res=0;
Shop shops[LIMIT];

bool cmpValue(Shop a, Shop b)
{
    return a.price < b.price;
}

bool cmpIndex(Shop a, Shop b)
{
    return a.index < b.index;
}

void solve()
{
    sort(shops,shops+n,cmpValue);
    for(int i=0;i<n;i++)
    {
        int curAmount = min(m,shops[i].amount);
        res += curAmount*shops[i].price;
        shops[i].bought = curAmount;
        m -= curAmount;
        if(m == 0) break;
    }
    sort(shops,shops+n,cmpIndex);
    cout << res << '\n';
    for(int i=0;i<n;i++)
    {
        cout << shops[i].bought << '\n';
    }
}

int main()
{
    cin >> m >> n;
    for(int i=0;i<n;i++)
    {
        cin >> shops[i].amount >> shops[i].price;
        shops[i].index = i;
        shops[i].bought = 0;
    }
    solve();
}
