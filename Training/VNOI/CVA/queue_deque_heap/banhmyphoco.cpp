#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;
ll res=0,r;

struct Ingredient
{
    ll number,price,need;
} ing[3];

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

ll moneyNeed(ll x)
{
    ll money = 0;
    for(int i=0;i<3;i++)
    {
        money += max(x*ing[i].need - ing[i].number,0LL) * ing[i].price;
    }
    return money;
}

int main()
{
    init();
    cin >> s;
    for(int i=0;i<3;i++)
    {
        cin >> ing[i].number;
        ing[i].need = 0;
    }
    for(int i=0;i<3;i++)
    {
        cin >> ing[i].price;
    }
    cin >> r;
    for(char c : s)
    {
        if(c == 'B')
        {
            ing[0].need++;
        }
        else if(c == 'S')
        {
            ing[1].need++;
        }
        else
        {
            ing[2].need++;
        }
    }
    ll left = 1,right = (ll) 1e12+101;
    while(left <= right)
    {
        ll mid = (left+right)/2;
        if(moneyNeed(mid) <= r)
        {
            left = mid+1;
            res = mid;
        }
        else
        {
            right = mid-1;
        }
    }
    cout << res;
}
