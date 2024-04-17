#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e5+5;
int t,n,k,a[LIMIT],res;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main()
{
    init();
    cin >> t;
    while(t--)
    {
        bool flag = false;
        cin >> n >> k;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        a[0] = 0;
        int i = n-k+1;
        while(a[i] == a[i-1])
        {
            i++;
            if(i > n)
            {
                cout << -1 << '\n';
                flag = true;
                break;
            }
        }
        if(flag == false)
            cout << a[i-1]+1 << '\n';
    }
}
