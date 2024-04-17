#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 1e5+5;
int n;
ll m,a[maxN],res=1,cur=0;

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        cur += a[i];
        if(cur > m)
        {
            res++;
            cur = a[i];
        }
    }
    cout << res;
}
