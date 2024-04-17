#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll x)
{
    bool flag = false;
    ll a = x;
    while(a != 0) {
        ll cur = a%10;
        if(cur != 6 && cur != 8) {
            flag = true;
            break;
        }
        a /= 10;
    }
    return !flag;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(check(a[i])) cnt++;
    }
    cout << cnt;
}
