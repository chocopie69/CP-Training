#include <bits/stdc++.h>
using namespace std;

int x,res=1;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> x)
    {
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=1;i<a.size();i++)
    {
        if(a[i] != a[i-1]) res++;
    }
    cout << res;
}
