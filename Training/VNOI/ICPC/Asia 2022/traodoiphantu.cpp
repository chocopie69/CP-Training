#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int maxN = 500002;
int n,m,a[maxN],pos[maxN],res=0;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

namespace sub1
{
    void solve()
    {
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            pos[a[i]] = i;
        }
        int x;
        char type;
        while(m--)
        {
            for(int i=1;i<=n;i++) pos[a[i]] = i;
            cin >> x >> type;
            int cur = pos[x];
            res += min(cur-1,n-cur);
            if(type == 'r')
            {
                for(int i=cur;i<n;i++)
                {
                    a[i] = a[i+1];
                }
                a[n] = x;
            }
            else
            {
                for(int i=cur;i>1;i--) a[i] = a[i-1];
                a[1] = x;
            }
            //for(int i=1;i<=n;i++) cout << a[i] << " ";
            cout << endl;
        }
        cout << res;
    }
}

int main()
{
    cin >> n >> m;
    if(n <= 4000 && m <= 4000) sub1::solve();
}

