#include <bits/stdc++.h>
using namespace std;

int n,cur=0,sum=0;

int main()
{
    cin >> n;
    int i=1;
    while(sum <= n)
    {
        cur+=i;
        sum+=cur;
        i++;
    }
    cout << i-2;
}
