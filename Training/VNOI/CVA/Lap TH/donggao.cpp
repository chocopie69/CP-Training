#include <bits/stdc++.h>
using namespace std;

int n,res=INT_MAX;
bool flag = false;

int main()
{
    cin >> n;
    for(int i=0;i<=n/5;i++)
    {
        int cur = n - 5*i;
        if(cur % 3 != 0) continue;
        res = min(res,i+cur/3);
        flag = true;
    }
    if(flag == false) cout << -1;
    else cout << res;
}
