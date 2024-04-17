#include <bits/stdc++.h>
using namespace std;

bool reversed(string x)
{
    string a = x;
    for(int i=0;i<a.length()/2;i++) swap(a[i],a[a.length()-i-1]);
    return a == x;
}

bool check(string x)
{
    bool flag = true;
    for(int i=1;i<x.length();i+=2)
    {
        if(i > 1 && x[i] != x[i-2]) flag = false;
    }
    return flag && reversed(x);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,res=0;
    string s;
    cin >> n >> s;
    if(n > 5000) return 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            string cur = s.substr(i,j-i+1);
            if(check(cur)) res++;
        }
    }
    cout << res;
}
