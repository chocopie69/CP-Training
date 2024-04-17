#include <bits/stdc++.h>
using namespace std;

int n,k,res=0;
queue<int> qu;

int main()
{
    cin >> n >> k;
    qu.push(n);
    while(!qu.empty())
    {
        int a = (qu.front() + k) / 2;
        int b = (qu.front() - k) / 2;
        if(a + b == qu.front() && a > 0 && b > 0)
        {
            qu.push(a);
            qu.push(b);
        }
        else
        {
            res++;
        }
        qu.pop();
    }
    cout << res;
}
