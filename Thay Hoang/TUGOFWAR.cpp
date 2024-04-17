#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 1e6+2;
int n,a[LIMIT],f[LIMIT],sum=0;
bool taken[LIMIT];
vector<int> nhom1,nhom2;

void init()
{
    memset(taken,false,sizeof(taken));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TUGOFWAR.INP","r",stdin);
    freopen("TUGOFWAR.OUT","w",stdout);
}

int main()
{
    //init();
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sum /= 2;
    f[0]=0;
    for(int i=1;i<=sum;i++)
    {
        f[i] = INT_MAX;
        for(int j=1;j<=n;j++)
        {
            if(a[j] <= i && f[i-a[j]] < j)
            {
                f[i] = j;
                break;
            }
        }
    }
    while(f[sum] == INT_MAX) sum--;
    while(sum > 0)
    {
        nhom1.push_back(f[sum]);
        taken[f[sum]] = true;
        sum -= a[f[sum]];
    }
    for(int i=1;i<=n;i++)
    {
        if(taken[i] == false) nhom2.push_back(i);
    }
    cout << nhom1.size() << " " << nhom2.size() << '\n';
    for(int v : nhom1)
    {
        cout << v << " ";
    }
    cout << '\n';
    for(int v: nhom2)
    {
        cout << v << " ";
    }
}
