#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e5+2;
int n,m,a[LIMIT],f[LIMIT],sum=0;
vector<int> res;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUBSETSUM.INP","r",stdin); freopen("SUBSETSUM.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if(m > sum)
    {
        cout << "NO";
        return 0;
    }
    f[0] = 0;
    for(int x=1;x<=sum;x++)
    {
        f[x] = INT_MAX;
        for(int i=1;i<=n;i++)
        {
            if(a[i] <= x && f[x-a[i]] < i)
            {
                f[x] = i;
                break;
            }
        }
    }
    if(f[m] == INT_MAX)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << '\n';
        while(m > 0)
        {
            res.push_back(f[m]);
            m -= a[f[m]];
        }
        for(int i=res.size()-1;i>=0;i--)
        {
            cout << res[i] << " ";
        }
    }
}
